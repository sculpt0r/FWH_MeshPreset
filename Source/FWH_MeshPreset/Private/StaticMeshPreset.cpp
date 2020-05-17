// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshPreset.h"

UStaticMesh* UStaticMeshPreset::GetAssignedMesh()
{
	return StaticMesh;
}
TArray<UMaterialInterface*> UStaticMeshPreset::GetMaterials()
{
	return Materials;
}
void UStaticMeshPreset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChanged)
{

	for (auto& spawnedActor : spawnedActors)
	{
		if (spawnedActor != nullptr)
		{
			UStaticMeshComponent* StaticMeshComponent = spawnedActor->GetStaticMeshComponent();
			StaticMeshComponent->UnregisterComponent();
			StaticMeshComponent->SetStaticMesh(StaticMesh);
			StaticMeshComponent->OverrideMaterials = Materials;

			StaticMeshComponent->RegisterComponent();
		}
	}
	const UObject* obj = PropertyChanged.GetObjectBeingEdited(0);

	UE_LOG(LogTemp, Log, TEXT("MeshPreset was changed: %s"), *obj->GetDetailedInfo());

}
