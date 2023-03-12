// Copyright (C) Microsoft. All rights reserved.

#pragma once


#include "SceneViewExtension.h"
#include "Network.h"

class FRealtimeStyleTransferViewExtension : public FSceneViewExtensionBase
{
public:
	FRealtimeStyleTransferViewExtension(const FAutoRegister& AutoRegister);
	static void SetStyle(const std::wstring& onnx_file_path);

	//~ ISceneViewExtension interface
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily) override {}
	virtual void PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override {}
	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override;
	virtual void SubscribeToPostProcessingPass(EPostProcessingPass PassId, FAfterPassCallbackDelegateArray& InOutPassCallbacks, bool bIsPassEnabled) override;
	
	FScreenPassTexture AfterTonemap_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessMaterialInputs& InOutInputs);

private:

	bool ViewExtensionIsActive;
	static Network* myNetwork;
	
	/*int Width;
	int Height;*/
	FRDGTextureRef AddStylePass_RenderThread(FRDGBuilder& GraphBuilder, FRDGTextureRef SourceTexture);

protected:
	FScreenPassTexture ApplyStyleTransfer(FRDGBuilder& GraphBuilder, const FPostProcessMaterialInputs& InOutInputs, const FString& DDSFileName);
};

