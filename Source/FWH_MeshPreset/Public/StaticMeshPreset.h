// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"

#include "Engine/StaticMeshActor.h"

#include "StaticMeshPreset.generated.h"
/**
 *
 */
UCLASS()
class FWH_MESHPRESET_API UStaticMeshPreset : public UObject//, public IAssetTypeActions
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere)
		TArray<UMaterialInterface*>Materials;
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChanged) override;
public:
	UStaticMesh* GetAssignedMesh();
	TArray<UMaterialInterface*> GetMaterials();
	TArray<AStaticMeshActor*> spawnedActors;
};
