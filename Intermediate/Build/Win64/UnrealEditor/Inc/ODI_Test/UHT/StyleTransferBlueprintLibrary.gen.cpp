// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ODI_Test/StyleTransferBlueprintLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStyleTransferBlueprintLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ODI_TEST_API UClass* Z_Construct_UClass_UStyleTransferBlueprintLibrary();
	ODI_TEST_API UClass* Z_Construct_UClass_UStyleTransferBlueprintLibrary_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ODI_Test();
// End Cross Module References
	DEFINE_FUNCTION(UStyleTransferBlueprintLibrary::execSetStyle)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ModelPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		UStyleTransferBlueprintLibrary::SetStyle(Z_Param_Out_ModelPath);
		P_NATIVE_END;
	}
	void UStyleTransferBlueprintLibrary::StaticRegisterNativesUStyleTransferBlueprintLibrary()
	{
		UClass* Class = UStyleTransferBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetStyle", &UStyleTransferBlueprintLibrary::execSetStyle },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics
	{
		struct StyleTransferBlueprintLibrary_eventSetStyle_Parms
		{
			FString ModelPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ModelPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::NewProp_ModelPath = { "ModelPath", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(StyleTransferBlueprintLibrary_eventSetStyle_Parms, ModelPath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::NewProp_ModelPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Style Transfer" },
		{ "ModuleRelativePath", "StyleTransferBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStyleTransferBlueprintLibrary, nullptr, "SetStyle", nullptr, nullptr, sizeof(Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::StyleTransferBlueprintLibrary_eventSetStyle_Parms), Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422601, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStyleTransferBlueprintLibrary);
	UClass* Z_Construct_UClass_UStyleTransferBlueprintLibrary_NoRegister()
	{
		return UStyleTransferBlueprintLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ODI_Test,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UStyleTransferBlueprintLibrary_SetStyle, "SetStyle" }, // 2540443016
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StyleTransferBlueprintLibrary.h" },
		{ "ModuleRelativePath", "StyleTransferBlueprintLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStyleTransferBlueprintLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::ClassParams = {
		&UStyleTransferBlueprintLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UStyleTransferBlueprintLibrary()
	{
		if (!Z_Registration_Info_UClass_UStyleTransferBlueprintLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStyleTransferBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UStyleTransferBlueprintLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStyleTransferBlueprintLibrary.OuterSingleton;
	}
	template<> ODI_TEST_API UClass* StaticClass<UStyleTransferBlueprintLibrary>()
	{
		return UStyleTransferBlueprintLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStyleTransferBlueprintLibrary);
	UStyleTransferBlueprintLibrary::~UStyleTransferBlueprintLibrary() {}
	struct Z_CompiledInDeferFile_FID_ODI_Test_Source_ODI_Test_StyleTransferBlueprintLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ODI_Test_Source_ODI_Test_StyleTransferBlueprintLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStyleTransferBlueprintLibrary, UStyleTransferBlueprintLibrary::StaticClass, TEXT("UStyleTransferBlueprintLibrary"), &Z_Registration_Info_UClass_UStyleTransferBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStyleTransferBlueprintLibrary), 2363330118U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ODI_Test_Source_ODI_Test_StyleTransferBlueprintLibrary_h_3236176925(TEXT("/Script/ODI_Test"),
		Z_CompiledInDeferFile_FID_ODI_Test_Source_ODI_Test_StyleTransferBlueprintLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ODI_Test_Source_ODI_Test_StyleTransferBlueprintLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
