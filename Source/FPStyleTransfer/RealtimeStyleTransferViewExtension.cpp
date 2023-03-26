// Copyright (C) Microsoft. All rights reserved.

#include "RealtimeStyleTransferViewExtension.h"

#include "Modules/ModuleManager.h"
#include "PostProcess/PostProcessMaterial.h"
#include "PostProcess/SceneRenderTargets.h"

// #include "MyNeuralNetwork.h"
#include "TensorTextureTranslate.h"

#include <vector>
#include <map>
#include "Math/PackedVector.h"

DEFINE_LOG_CATEGORY_STATIC(LogRealtimeStyleTransfer, Log, All);
// void RenderMyTest(FRHICommandList &RHICmdList, ERHIFeatureLevel::Type FeatureLevel, const FLinearColor &Color);

namespace RealtimeStyleTransfer
{
	static int32 IsActive = 0;
	static FAutoConsoleVariableRef CVarStyleTransferIsActive(
		TEXT("r.RealtimeStyleTransfer.Enable"),
		IsActive,
		TEXT("Allows an additional rendering pass that will apply a neural style to the frame.\n")
			TEXT("=0:off (default), >0: on"),
		ECVF_Cheat | ECVF_RenderThreadSafe);


} 
//------------------------------------------------------------------------------
FRealtimeStyleTransferViewExtension::FRealtimeStyleTransferViewExtension(const FAutoRegister &AutoRegister)
	: FSceneViewExtensionBase(AutoRegister)
{
	ViewExtensionIsActive = GDynamicRHI->GetName() == FString(TEXT("D3D12"));
}

//------------------------------------------------------------------------------
Network* FRealtimeStyleTransferViewExtension::myNetwork = new Network(L"D:/UGit/ODI-TestProject/Source/Model/optimized-candy-9.onnx", "StyleTransfer");

//------------------------------------------------------------------------------
void FRealtimeStyleTransferViewExtension::SetStyle(const std::wstring& onnx_file_path)
{
	myNetwork = new Network(onnx_file_path, "StyleTransfer");
}

//------------------------------------------------------------------------------
bool FRealtimeStyleTransferViewExtension::IsActiveThisFrame_Internal(const FSceneViewExtensionContext &Context) const
{
	return ViewExtensionIsActive;
}


FRDGTextureRef FRealtimeStyleTransferViewExtension::AddStylePass_RenderThread(
	FRDGBuilder &GraphBuilder,
	FRDGTextureRef SourceTexture)
{
	if (SourceTexture == nullptr)
	{
		UE_LOG(LogRealtimeStyleTransfer, Warning, TEXT("Skipping null texture"));
		return SourceTexture;
	}

	uint32 TextureWidth = SourceTexture->Desc.Extent.X;
	uint32 TextureHeight = SourceTexture->Desc.Extent.Y;
	uint32 BufferWidth = 224;
	uint32 BufferHeight = 224;
	auto SourceBuffer = DispatchTexture2Tensor(GraphBuilder, TextureWidth, TextureHeight, BufferWidth, BufferHeight, SourceTexture);
	// auto OutputBuffer = DispatchTexture2Tensor(GraphBuilder, TextureWidth, TextureHeight, BufferWidth, BufferHeight, OutputTexture);
	FRDGBufferDesc BufferDesc = FRDGBufferDesc::CreateBufferDesc(sizeof(uint16_t), BufferWidth * BufferHeight * 3); // half
	auto OutputBuffer = GraphBuilder.CreateBuffer(BufferDesc, TEXT("OutputTensor"));

	myNetwork->CreateModelAndUploadData(GraphBuilder);
	myNetwork->ExecuteInference(GraphBuilder, 
		std::map<std::string, FRDGBufferRef>{ {"input1", SourceBuffer} }, OutputBuffer);
	return DispatchTensor2Texture(GraphBuilder, TextureWidth, TextureHeight, BufferWidth, BufferHeight, OutputBuffer, SourceTexture->Desc);
}

//------------------------------------------------------------------------------
void FRealtimeStyleTransferViewExtension::SubscribeToPostProcessingPass(EPostProcessingPass PassId, FAfterPassCallbackDelegateArray &InOutPassCallbacks, bool bIsPassEnabled)
{
	if (!RealtimeStyleTransfer::IsActive)
	{
		return;
	}

	if (!bIsPassEnabled)
	{
		return;
	}

	if (PassId == EPostProcessingPass::Tonemap) {
		InOutPassCallbacks.Add(FAfterPassCallbackDelegate::CreateRaw(this, &FRealtimeStyleTransferViewExtension::AfterTonemap_RenderThread));
	}
}

//------------------------------------------------------------------------------
FScreenPassTexture FRealtimeStyleTransferViewExtension::ApplyStyleTransfer(FRDGBuilder &GraphBuilder, const FPostProcessMaterialInputs &InOutInputs, const FString &DDSFileName)
{
	FRDGTextureRef InputTexture = nullptr;
	FScreenPassTexture ReturnTexture;

	if (InOutInputs.OverrideOutput.IsValid())
	{
		InputTexture = InOutInputs.OverrideOutput.Texture;
		ReturnTexture = InOutInputs.OverrideOutput;
	}
	else
	{
		InputTexture = InOutInputs.Textures[(uint32)EPostProcessMaterialInput::SceneColor].Texture;
		
		ReturnTexture = const_cast<FScreenPassTexture &>(InOutInputs.Textures[(uint32)EPostProcessMaterialInput::SceneColor]);
	}
	
	ReturnTexture.Texture = AddStylePass_RenderThread(GraphBuilder, InputTexture);

	return ReturnTexture;
}

//------------------------------------------------------------------------------
FScreenPassTexture FRealtimeStyleTransferViewExtension::AfterTonemap_RenderThread(FRDGBuilder &GraphBuilder, const FSceneView &View, const FPostProcessMaterialInputs &InOutInputs)
{
	RDG_EVENT_SCOPE(GraphBuilder, "RealtimeStyleTransfer_AfterTonemap");

	return ApplyStyleTransfer(GraphBuilder, InOutInputs, FString::Printf(TEXT("After%02dTonemap"), EPostProcessingPass::Tonemap));
}


#undef LOCTEXT_NAMESPACE
