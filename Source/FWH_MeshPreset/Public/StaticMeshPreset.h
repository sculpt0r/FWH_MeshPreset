// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "StaticMeshPreset.generated.h"

/**
 *
 */
UCLASS(hidecategories = Object)
class FWH_MESHPRESET_API UStaticMeshPreset : public UObject
{
	GENERATED_BODY()
//protected:
	UPROPERTY(EditAnywhere)
		FString Description;
};
