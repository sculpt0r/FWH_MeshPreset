// Copyright Epic Games, Inc. All Rights Reserved.

#include "FWH_MeshPresetGameMode.h"
#include "FWH_MeshPresetPawn.h"

AFWH_MeshPresetGameMode::AFWH_MeshPresetGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AFWH_MeshPresetPawn::StaticClass();
}

