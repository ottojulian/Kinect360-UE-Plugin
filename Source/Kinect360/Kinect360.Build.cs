using UnrealBuildTool;
using System;
using System.IO;

public class Kinect360 : ModuleRules
{
    public Kinect360(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseRTTI = false;
        bEnableExceptions = false;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Projects",
            "InputCore"
        });

        PublicIncludePaths.AddRange(new string[]
        {
            Path.Combine(ModuleDirectory, "Public")
        });

        PrivateIncludePaths.AddRange(new string[]
        {
            Path.Combine(ModuleDirectory, "Private")
        });

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string KinectSdkRoot = Environment.GetEnvironmentVariable("KINECTSDK10_DIR");

            if (string.IsNullOrEmpty(KinectSdkRoot))
            {
                KinectSdkRoot = @"C:\Program Files\Microsoft SDKs\Kinect\v1.8\";
            }

            if (Directory.Exists(KinectSdkRoot))
            {
                PublicIncludePaths.Add(Path.Combine(KinectSdkRoot, "inc"));

                string LibraryDir = Path.Combine(KinectSdkRoot, "lib", "amd64");
                if (!Directory.Exists(LibraryDir))
                {
                    LibraryDir = Path.Combine(KinectSdkRoot, "lib", "x64");
                }

                if (Directory.Exists(LibraryDir))
                {
                    PublicAdditionalLibraries.Add(Path.Combine(LibraryDir, "Kinect10.lib"));
                }
                else
                {
                    PublicDefinitions.Add("KINECT360_SDK_NOT_FOUND=1");
                }
            }
            else
            {
                PublicDefinitions.Add("KINECT360_SDK_NOT_FOUND=1");
            }
        }
        else
        {
            PublicDefinitions.Add("KINECT360_PLATFORM_UNSUPPORTED=1");
        }
    }
}
