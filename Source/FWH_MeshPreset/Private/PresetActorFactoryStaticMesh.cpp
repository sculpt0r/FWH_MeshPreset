// Fill out your copyright notice in the Description page of Project Settings.


#include "PresetActorFactoryStaticMesh.h"
#include "Engine/StaticMeshActor.h"

#include "StaticMeshPreset.h"

UPresetActorFactoryStaticMesh::UPresetActorFactoryStaticMesh(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = FText::FromString("StaticMeshDisplayName TEST");// , "Static Mesh TEST");
	NewActorClass = AStaticMeshActor::StaticClass();
	bUseSurfaceOrientation = true;
}
//
bool UPresetActorFactoryStaticMesh::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	/*	if (!AssetData.IsValid() || !AssetData.GetClass()->IsChildOf(UStaticMeshPreset::StaticClass()))
		{
			OutErrorMsg =*/ NSLOCTEXT("CanCreateActor", "NoStaticMesh", "A valid static mesh must be specified.");
return false;
//}
////
//return true;
}
//
void UPresetActorFactoryStaticMesh::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	//Super::PostSpawnActor(Asset, NewActor);
	AStaticMeshActor* StaticMeshActor = CastChecked<AStaticMeshActor>(NewActor);

	////
	////	UStaticMesh* StaticMesh = CastChecked<UStaticMesh>(Asset);
	////
	////	UE_LOG(LogActorFactory, Log, TEXT("Actor Factory created %s"), *StaticMesh->GetName());
	////
	////	// Change properties
	////	AStaticMeshActor* StaticMeshActor = CastChecked<AStaticMeshActor>(NewActor);
	////	UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
	////	check(StaticMeshComponent);
	////
	////	StaticMeshComponent->UnregisterComponent();
	////
	////	StaticMeshComponent->SetStaticMesh(StaticMesh);
	////	if (StaticMesh->RenderData)
	////	{
	////		StaticMeshComponent->StaticMeshDerivedDataKey = StaticMesh->RenderData->DerivedDataKey;
	////	}
	////
	////	// Init Component
	////	StaticMeshComponent->RegisterComponent();
}
//
UObject* UPresetActorFactoryStaticMesh::GetAssetFromActorInstance(AActor* Instance)
{
	//	//WAHT TO RETURN HERE?
	check(Instance->IsA(NewActorClass));
	AStaticMeshActor* SMA = CastChecked<AStaticMeshActor>(Instance);
	//
	check(SMA->GetStaticMeshComponent());
	return SMA->GetStaticMeshComponent()->GetStaticMesh();
}
//
void UPresetActorFactoryStaticMesh::PostCreateBlueprint(UObject* Asset, AActor* CDO)
{
	//	if (Asset != NULL && CDO != NULL)
	//	{
	//		UStaticMesh* StaticMesh = CastChecked<UStaticMesh>(Asset);
	//		AStaticMeshActor* StaticMeshActor = CastChecked<AStaticMeshActor>(CDO);
	//		UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
	//
	//		StaticMeshComponent->SetStaticMesh(StaticMesh);
	//		StaticMeshComponent->StaticMeshDerivedDataKey = StaticMesh->RenderData->DerivedDataKey;
	//	}
}
//
FQuat UPresetActorFactoryStaticMesh::AlignObjectToSurfaceNormal(const FVector& InSurfaceNormal, const FQuat& ActorRotation) const
{
	//	// Meshes align the Z (up) axis with the surface normal
	return FindActorAlignmentRotation(ActorRotation, FVector(0.f, 0.f, 1.f), InSurfaceNormal);
}
