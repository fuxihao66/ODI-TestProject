// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPStyleTransfer.h"
#include "Modules/ModuleManager.h"
#include "RealtimeStyleTransferViewExtension.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FPStyleTransferModule, FPStyleTransfer, "FPStyleTransfer" );

void FPStyleTransferModule::StartupModule()
{
	FString ModuleDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("TemaranShaderTutorial"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/ProjectShaders"), ModuleDir);

	RealtimeStyleTransferViewExtension = FSceneViewExtensions::NewExtension<FRealtimeStyleTransferViewExtension>();
}
 