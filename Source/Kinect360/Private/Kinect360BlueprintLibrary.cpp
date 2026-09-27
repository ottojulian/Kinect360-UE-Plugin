#include "Kinect360BlueprintLibrary.h"
#include "Kinect360Sensor.h"
#include "Kinect360Module.h"

bool UKinect360BlueprintLibrary::IsSupported()
{
#if PLATFORM_WINDOWS
    return true;
#else
    return false;
#endif
}

void UKinect360BlueprintLibrary::GetSensorStatus(EKinect360Status& OutStatus, FString& OutMessage)
{
#if PLATFORM_WINDOWS
    OutStatus = EKinect360Status::Ready;
    OutMessage = TEXT("Windows detected. Install the Kinect for Windows SDK v1.8 to enable hardware IO.");
#else
    OutStatus = EKinect360Status::NotSupported;
    OutMessage = TEXT("Kinect 360 is only supported on Win64.");
#endif
}

bool UKinect360BlueprintLibrary::StartSensor()
{
    static FKinect360Sensor Sensor;
    return Sensor.Initialize();
}

void UKinect360BlueprintLibrary::StopSensor()
{
    static FKinect360Sensor Sensor;
    Sensor.Shutdown();
}
