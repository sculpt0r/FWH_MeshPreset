// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
//#include "StaticMeshPreset.h"
#include "StaticMeshPresetFactory.generated.h"

/**
 *Factory for presets
 */

UCLASS(HideCategories = Object)
class FWH_MESHPRESET_API UStaticMeshPresetFactory : public UFactory
{
	GENERATED_BODY()
		UStaticMeshPresetFactory(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

	virtual void PostEditChangeProperty
	(
		struct FPropertyChangedEvent & PropertyChangedEvent
	) override;
};
