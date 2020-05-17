// Fill out your copyright notice in the Description page of Project Settings.


#include "PresetActorFactory.h"
#include "Engine/StaticMeshActor.h"
#include "StaticMeshPreset.h"

UPresetActorFactory::UPresetActorFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = FText::FromString("StaticMeshDisplayName TEST");// , "Static Mesh TEST");
	NewActorClass = AStaticMeshActor::StaticClass();
	bUseSurfaceOrientation = true;
}

bool UPresetActorFactory::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	if (!AssetData.IsValid() || !AssetData.GetClass()->IsChildOf(UStaticMeshPreset::StaticClass()))
	{
		OutErrorMsg = NSLOCTEXT("CanCreateActor", "NoStaticMesh", "A valid static mesh must be specified.");
		return false;
	}
	//
	return true;
}
void UPresetActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);
	UE_LOG(LogTemp, Log, TEXT("******************UPresetActorFactory::Post Spawn ACtor !!!!! ******************"));
	UStaticMeshPreset* meshPreset = CastChecked<UStaticMeshPreset>(Asset);

	UStaticMesh* StaticMesh = meshPreset->GetAssignedMesh();

	AStaticMeshActor* StaticMeshActor = CastChecked<AStaticMeshActor>(NewActor);
	UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
	check(StaticMeshComponent);

	StaticMeshComponent->UnregisterComponent();

	StaticMeshComponent->SetStaticMesh(StaticMesh);
	if (StaticMesh->RenderData)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh has some render data!"));
		StaticMeshComponent->StaticMeshDerivedDataKey = StaticMesh->RenderData->DerivedDataKey;

		auto mats = meshPreset->GetMaterials();
		int32 materialIndex = 0;
		for (auto& materialI : mats)
		{
			UE_LOG(LogTemp, Log, TEXT("Added material!"));

			StaticMeshComponent->SetMaterial(materialIndex, materialI);
			++materialIndex;
		}
	}
	else {

		UE_LOG(LogTemp, Log, TEXT("Mesh DONT! has some render data!"));
	}

	// Init Component
	StaticMeshComponent->RegisterComponent();
}

void UPresetActorFactory::PostCreateBlueprint(UObject* Asset, AActor* CDO)
{
	UE_LOG(LogTemp, Log, TEXT("******************1UPresetActorFactory::Post Spawn ACtor !!!!! ******************"));
	AStaticMeshActor* StaticMeshActor = CastChecked<AStaticMeshActor>(CDO);

	FString newName = "My custom Freak Name";

	StaticMeshActor->Rename(*newName);
	StaticMeshActor->SetActorLabel(*newName);
}
