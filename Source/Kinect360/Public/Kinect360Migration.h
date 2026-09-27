#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.h"

#define KINECT360_LEGACY_WRAPPER(CallExpression) \
    do { \
        if (Kinect360Migration::IsCompatibleWithLegacyCode()) \
        { \
            (CallExpression); \
        } \
    } while (0)

namespace Kinect360Migration
{
    FName GetCurrentMigrationModeName();
    bool IsCompatibleWithLegacyCode();
    void LogMigrationNotice();
}
