// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "PresetActorFactory.generated.h"

/**
 *
 */
UCLASS()
class FWH_MESHPRESET_API UPresetActorFactory : public UActorFactory
{
	GENERATED_BODY()
		UPresetActorFactory(const FObjectInitializer& ObjectInitializer);
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override;
	virtual void PostSpawnActor(UObject* Asset, AActor* NewActor) override;
	virtual void PostCreateBlueprint(UObject* Asset, AActor* CDO) override;
};
