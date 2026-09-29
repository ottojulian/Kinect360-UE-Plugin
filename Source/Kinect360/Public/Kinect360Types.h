#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.generated.h"

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
    TArray<FKinect360Joint> Joints;
};
