#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FKinect360Module : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    static void LogStatus(const FString& Message);
    static bool IsKinectSdkAvailable();
};
