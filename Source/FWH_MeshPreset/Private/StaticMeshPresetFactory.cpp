// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshPresetFactory.h"
#include "StaticMeshPreset.h"

UStaticMeshPresetFactory::UStaticMeshPresetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	SupportedClass = UStaticMeshPreset::StaticClass();
}

UObject* UStaticMeshPresetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	FString fs = InParent->GetPathName();
	return NewObject<UStaticMeshPreset>(InParent, Class, Name, Flags);
}
void  UStaticMeshPresetFactory::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
