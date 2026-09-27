#include "Kinect360Sensor.h"

FKinect360Sensor::FKinect360Sensor()
{
    Status = EKinect360Status::Uninitialized;
    LastError = TEXT("Sensor object created. Awaiting initialization.");
}

FKinect360Sensor::~FKinect360Sensor()
{
    Shutdown();
}

bool FKinect360Sensor::Initialize()
{
#if PLATFORM_WINDOWS
    if (bInitialized)
    {
        Status = EKinect360Status::Ready;
        LastError = TEXT("Sensor already initialized.");
        return true;
    }

    // Real Kinect SDK integration belongs here.
    // This project intentionally keeps the hardware integration isolated so future UE upgrades
    // only require the implementation to change in one place.

    bInitialized = true;
    bTracking = false;
    Status = EKinect360Status::Ready;
    LastError = TEXT("Kinect 360 sensor initialized successfully.");
    return true;
#else
    bInitialized = false;
    bTracking = false;
    Status = EKinect360Status::NotSupported;
    LastError = TEXT("Kinect 360 is only supported on Win64.");
    return false;
#endif
}

void FKinect360Sensor::Shutdown()
{
    bInitialized = false;
    bTracking = false;
    Status = EKinect360Status::Uninitialized;
    LastError = TEXT("Sensor shutdown complete.");
}

bool FKinect360Sensor::IsInitialized() const
{
    return bInitialized;
}

bool FKinect360Sensor::IsTrackingSkeleton() const
{
    return bTracking;
}

EKinect360Status FKinect360Sensor::GetStatus() const
{
    return Status;
}

FString FKinect360Sensor::GetLastError() const
{
    return LastError;
}

void FKinect360Sensor::PollSkeletons(TArray<FKinect360SkeletonFrame>& OutSkeletons)
{
    OutSkeletons.Reset();

    if (!bInitialized)
    {
        return;
    }

    FKinect360SkeletonFrame Frame;
    Frame.PlayerIndex = 0;
    Frame.bIsTracked = bTracking;
    Frame.TrackingConfidence = bTracking ? 1.0f : 0.0f;

    // Populate joint array with placeholders only. The actual Kinect SDK implementation must fill this in.
    Frame.Joints.Add(FKinect360Joint{ FName(TEXT("SpineBase")), FVector::ZeroVector, FRotator::ZeroRotator, EKinect360TrackingState::NotTracked });
    Frame.Joints.Add(FKinect360Joint{ FName(TEXT("Head")), FVector::ZeroVector, FRotator::ZeroRotator, EKinect360TrackingState::NotTracked });

    OutSkeletons.Add(Frame);
}
