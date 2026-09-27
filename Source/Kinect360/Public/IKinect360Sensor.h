#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.h"

class IKinect360Sensor
{
public:
    virtual ~IKinect360Sensor() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;
    virtual bool IsInitialized() const = 0;
    virtual bool IsTrackingSkeleton() const = 0;
    virtual EKinect360Status GetStatus() const = 0;
    virtual FString GetLastError() const = 0;
    virtual void PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons) = 0;
};
