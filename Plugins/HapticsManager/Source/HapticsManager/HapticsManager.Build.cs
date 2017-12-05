// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class HapticsManager : ModuleRules
{
    public HapticsManager(ReadOnlyTargetRules Target): base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.AddRange(
			new string[] {
                "HapticsManager/Public",
                "Utility/Include"
				// ... add public include paths required here ...
			}
			);
				
		PrivateIncludePaths.AddRange(
			new string[] {
                "HapticsManager/Private",
				// ... add other private include paths required here ...
			}
			);
			
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "HapticsManager",
                //"System",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "HapticsManager",
                "Json",
                "JsonUtilities",
                "Projects"
                //"Sockets",
				// ... add private dependencies that you statically link with here ...	
			}
			);

        //string BinaryLocation = Directory.GetParent(ModuleDirectory).ToString();
        ////PublicIncludePaths.Add(BinaryLocation + @"DLLs\Include");
        ////PublicIncludePaths.Add(BinaryLocation + @"Utility\Include");

        //PublicAdditionalLibraries.Add(BinaryLocation + @"\Utility\Libraries\HapticUtility.lib");//D:\bHapticsManager\bHapticsRelease - Gitlab\Plugins\HapticsManager\Binaries\Win64\bHapticUtility.lib
        bool isLibrarySupported = false;
        string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory,"../../ThirdParty/"));

        if ((Target.Platform == UnrealTargetPlatform.Win64) )
        {
            isLibrarySupported = true;
            
            string LibrariesPath = Path.Combine(ThirdPartyPath, "Utility", "Libraries");

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "HapticUtility.x64.lib"));
        }

        if (isLibrarySupported)
        {
            // Include path
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Utility", "Includes"));
        }

        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

	}
}
