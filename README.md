# Kinect360 UE Plugin

A migration-friendly Unreal Engine 5.5 plugin for Microsoft Kinect 360 devices.

This repository is intentionally organized as a clean runtime plugin so you can copy it into a project's `Plugins/` folder and enable it from the editor without having to rewrite every existing Kinect-related subsystem in one pass.

## Supported target

- Unreal Engine 5.5
- Platform: Win64
- Hardware: Kinect for Windows v1 (Kinect 360)

## Installation

1. Copy this directory into your project's plugin folder:

```text
<YourProject>/Plugins/Kinect360/
```

2. Open the Unreal editor.
3. Go to Edit -> Plugins.
4. Search for `Kinect 360` and enable the plugin.
5. Restart the editor and rebuild the project if needed.

## Important note about the Kinect SDK

This plugin requires the Microsoft Kinect for Windows SDK v1.8 being installed on your machine.

Typical SDK install location:

```text
C:\Program Files\Microsoft SDKs\Kinect\v1.8\
```

## What is included

- Plugin descriptor for UE 5.5
- Runtime module skeleton
- Blueprint-accessible sensor status functions
- Compatibility/migration helpers for legacy Kinect code
- Basic sensor abstraction layer to keep your game code from being tightly coupled to raw SDK calls


## Recommended project layout

```text
YourProject/
  Plugins/
    Kinect360/
      Kinect360.uplugin
      Source/
        Kinect360/
          Public/
          Private/
```

## Troubleshooting

- If the plugin is not visible in the editor, ensure the project has regenerated project files.
- If Windows-specific builds fail, verify that the Kinect SDK is installed and the `KINECTSDK10_DIR` environment variable is set or the default install path is present.
- If the editor drops the plugin during engine upgrades, update the plugin build scripts and recompile the project.

## MIT License


