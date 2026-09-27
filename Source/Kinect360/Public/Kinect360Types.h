#pragma once

#include "CoreMinimal.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"

UENUM(BlueprintType)
enum class EKinect360TrackingState : uint8
{
    NotTracked UMETA(DisplayName = "Not Tracked"),
    Inferred UMETA(DisplayName = "Inferred"),
    Tracked UMETA(DisplayName = "Tracked")
};

UENUM(BlueprintType)
enum class EKinect360Status : uint8
{
    Uninitialized UMETA(DisplayName = "Uninitialized"),
    Ready UMETA(DisplayName = "Ready"),
    Error UMETA(DisplayName = "Error"),
    NotSupported UMETA(DisplayName = "Not Supported")
};

USTRUCT(BlueprintType)
struct FKinect360Joint
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    FName JointName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    FVector Position = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    FRotator Orientation = FRotator::ZeroRotator;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    EKinect360TrackingState TrackingState = EKinect360TrackingState::NotTracked;
};

USTRUCT(BlueprintType)
struct FKinect360SkeletonFrame
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    int32 PlayerIndex = -1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    bool bIsTracked = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    float TrackingConfidence = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinect360")
    TArray<FKinect360Joint> Joints;
};
