// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeODI_Test_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ODI_Test;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ODI_Test()
	{
		if (!Z_Registration_Info_UPackage__Script_ODI_Test.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ODI_Test",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x20839879,
				0x90F2AF83,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ODI_Test.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ODI_Test.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ODI_Test(Z_Construct_UPackage__Script_ODI_Test, TEXT("/Script/ODI_Test"), Z_Registration_Info_UPackage__Script_ODI_Test, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x20839879, 0x90F2AF83));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
