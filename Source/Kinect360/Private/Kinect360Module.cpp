#include "Kinect360Module.h"
#include "Kinect360Migration.h"

#define LOCTEXT_NAMESPACE "Kinect360"

IMPLEMENT_MODULE(FKinect360Module, Kinect360)

void FKinect360Module::StartupModule()
{
    UE_LOG(LogTemp, Log, TEXT("Kinect360 plugin startup complete."));
    Kinect360Migration::LogMigrationNotice();
}

void FKinect360Module::ShutdownModule()
{
    UE_LOG(LogTemp, Log, TEXT("Kinect360 plugin shutdown complete."));
}

void FKinect360Module::LogStatus(const FString& Message)
{
    UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
}

bool FKinect360Module::IsKinectSdkAvailable()
{
#if PLATFORM_WINDOWS
    return true;
#else
    return false;
#endif
}

#undef LOCTEXT_NAMESPACE
