// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshPresetFactory.h"
#include "StaticMeshPreset.h"
//#include "AssetTypeCategories.h"
//#define LOCTEXT_NAMESPACE "Paper 2D"

UStaticMeshPresetFactory::UStaticMeshPresetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	SupportedClass = UStaticMeshPreset::StaticClass();
}

UObject* UStaticMeshPresetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UStaticMeshPreset>(InParent, Class, Name, Flags);
}
//uint32 UStaticMeshPresetFactory::GetMenuCategories() const
//{
//	//Let's place this asset in the Blueprints category in the Editor
//	return EAssetTypeCategories::Blueprint;
//}
////virtual UObject* FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn) override;
//bool UStaticMeshPresetFactory::DoesSupportClass(UClass * Class)
//{
//	return Class == UStaticMeshPreset::StaticClass();
//}
//virtual bool FactoryCanImport(const FString& Filename) override;

//#undef LOCTEXT_NAMESPACE
