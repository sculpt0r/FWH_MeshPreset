// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"

//#include "IAssetTypeActions.h"

#include "StaticMeshPreset.generated.h"

/**
 *
 */
//UCLASS(meta=(BlueprintSpawnableComponent))
UCLASS()
class FWH_MESHPRESET_API UStaticMeshPreset : public UObject//, public IAssetTypeActions
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere)
		TArray<UMaterialInterface*>Materials;

public:
	UStaticMesh* GetAssignedMesh();
};
