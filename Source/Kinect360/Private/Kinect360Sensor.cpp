#include "Kinect360Sensor.h"

FKinect360Sensor::FKinect360Sensor()
    : bInitialized(false)
    , Status(EKinect360Status::Uninitialized)
    , LastError(TEXT("Not initialized"))
{
}

FKinect360Sensor::~FKinect360Sensor()
{
    Shutdown();
}

bool FKinect360Sensor::Initialize()
{
    // Minimal scaffold: mark ready but do not require native SDK.
    bInitialized = true;
    Status = EKinect360Status::Ready;
    LastError = TEXT("Initialized (stub). Replace with Kinect SDK integration.");
    return true;
}

void FKinect360Sensor::Shutdown()
{
    bInitialized = false;
    Status = EKinect360Status::Uninitialized;
    LastError = TEXT("Shutdown (stub).");
    LatestSkeletons.Reset();
}

bool FKinect360Sensor::IsInitialized() const
{
    return bInitialized;
}

EKinect360Status FKinect360Sensor::GetStatus() const
{
    return Status;
}

void FKinect360Sensor::PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons)
{
    // Return whatever is stored (stub). Consumers can replace with SDK polling.
    OutSkeletons = LatestSkeletons;
}
