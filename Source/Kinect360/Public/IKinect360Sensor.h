#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.h"

// Pure C++ interface (no UHT) for sensor backends.
class IKinect360Sensor
{
public:
    virtual ~IKinect360Sensor() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;
    virtual bool IsInitialized() const = 0;
    virtual EKinect360Status GetStatus() const = 0;
    virtual void PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons) = 0;
};
