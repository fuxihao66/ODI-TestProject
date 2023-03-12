// Fill out your copyright notice in the Description page of Project Settings.


#include "StyleTransferBlueprintLibrary.h"

#include "RealtimeStyleTransferViewExtension.h"

UStyleTransferBlueprintLibrary::UStyleTransferBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
void UStyleTransferBlueprintLibrary::SetStyle(FString& ModelPath)
{
	std::wstring onnx_file_path = std::wstring(*ModelPath);

	FRealtimeStyleTransferViewExtension::SetStyle(onnx_file_path);
}
