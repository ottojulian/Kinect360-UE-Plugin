#include "Kinect360Migration.h"
#include "Kinect360Module.h"

namespace Kinect360Migration
{
    FName GetCurrentMigrationModeName()
    {
        return FName(TEXT("UnrealEngine_5_5_Compatibility"));
    }

    bool IsCompatibleWithLegacyCode()
    {
        return true;
    }

    void LogMigrationNotice()
    {
        UE_LOG(LogTemp, Log, TEXT("Kinect360 migration wrapper active. Use the plugin API to isolate legacy SDK integration from gameplay code."));
    }
}
