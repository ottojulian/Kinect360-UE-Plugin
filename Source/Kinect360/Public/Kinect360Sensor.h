#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.h"

class FKinect360Sensor : public IKinect360Sensor
{
public:
    FKinect360Sensor();
    virtual ~FKinect360Sensor() override;

    virtual bool Initialize() override;
    virtual void Shutdown() override;
    virtual bool IsInitialized() const override;
    virtual bool IsTrackingSkeleton() const override;
    virtual EKinect360Status GetStatus() const override;
    virtual FString GetLastError() const override;
    virtual void PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons) override;

private:
    bool bInitialized = false;
    bool bTracking = false;
    EKinect360Status Status = EKinect360Status::Uninitialized;
    FString LastError = TEXT("Not initialized");
};
