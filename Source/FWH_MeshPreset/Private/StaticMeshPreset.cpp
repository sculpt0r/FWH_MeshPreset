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
