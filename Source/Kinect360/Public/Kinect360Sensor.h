#pragma once

#include "CoreMinimal.h"
#include "IKinect360Sensor.h"

// Minimal concrete sensor implementation (no SDK calls).
class FKinect360Sensor : public IKinect360Sensor
{
public:
    FKinect360Sensor();
    virtual ~FKinect360Sensor() override;

    virtual bool Initialize() override;
    virtual void Shutdown() override;
    virtual bool IsInitialized() const override;
    virtual EKinect360Status GetStatus() const override;
    virtual void PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons) override;

private:
    bool bInitialized;
    EKinect360Status Status;
    FString LastError;

    TArray<FKinect360SkeletonFrame> LatestSkeletons;
};
