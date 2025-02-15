// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FWH_MeshPreset : ModuleRules
{
	public FWH_MeshPreset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
