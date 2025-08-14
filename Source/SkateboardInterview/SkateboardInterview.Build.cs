// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SkateboardInterview : ModuleRules
{
	public SkateboardInterview(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SkateboardInterview",
			"SkateboardInterview/Variant_Platforming",
			"SkateboardInterview/Variant_Platforming/Animation",
			"SkateboardInterview/Variant_Combat",
			"SkateboardInterview/Variant_Combat/AI",
			"SkateboardInterview/Variant_Combat/Animation",
			"SkateboardInterview/Variant_Combat/Gameplay",
			"SkateboardInterview/Variant_Combat/Interfaces",
			"SkateboardInterview/Variant_Combat/UI",
			"SkateboardInterview/Variant_SideScrolling",
			"SkateboardInterview/Variant_SideScrolling/AI",
			"SkateboardInterview/Variant_SideScrolling/Gameplay",
			"SkateboardInterview/Variant_SideScrolling/Interfaces",
			"SkateboardInterview/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
