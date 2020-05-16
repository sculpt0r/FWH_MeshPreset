// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/Object.h"
//#include "GameFramework/Actor.h"

#include "ActorFactories/ActorFactoryStaticMesh.h"
#include "PresetActorFactoryStaticMesh.generated.h"
//class AActor;
//class UObject;
//struct FAssetData;
/**
 *
 */
UCLASS()
class FWH_MESHPRESET_API UPresetActorFactoryStaticMesh : public UActorFactoryStaticMesh
{
	GENERATED_BODY()
		UPresetActorFactoryStaticMesh(const FObjectInitializer& ObjectInitializer);
	//~ Begin UActorFactory Interface
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override;
	virtual void PostSpawnActor(UObject* Asset, AActor* NewActor) override;
	virtual void PostCreateBlueprint(UObject* Asset, AActor* CDO) override;
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance) override;
	virtual FQuat AlignObjectToSurfaceNormal(const FVector& InSurfaceNormal, const FQuat& ActorRotation) const override;
	//~ End UActorFactory Interface
};
