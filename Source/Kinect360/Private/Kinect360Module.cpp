#include "Kinect360Module.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"

IMPLEMENT_MODULE(FKinect360Module, Kinect360)

void FKinect360Module::StartupModule()
{
    UE_LOG(LogTemp, Log, TEXT("Kinect360 module started (baseline)."));
}

void FKinect360Module::ShutdownModule()
{
    UE_LOG(LogTemp, Log, TEXT("Kinect360 module shutdown."));
}
