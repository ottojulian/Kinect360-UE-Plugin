#include "Kinect360BlueprintLibrary.h"
#include "Kinect360Sensor.h"

// Single static sensor instance for simple use
static FKinect360Sensor GSensor;

bool UKinect360BlueprintLibrary::IsSupported()
{
#if PLATFORM_WINDOWS
    // SDK integration will be added later; declare platform support here.
    return true;
#else
    return false;
#endif
}

bool UKinect360BlueprintLibrary::StartSensor()
{
    return GSensor.Initialize();
}

void UKinect360BlueprintLibrary::StopSensor()
{
    GSensor.Shutdown();
}

TArray<FKinect360SkeletonFrame> UKinect360BlueprintLibrary::PollSkeletons()
{
    TArray<FKinect360SkeletonFrame> Out;
    GSensor.PollSkeletons(Out);
    return Out;
}
    