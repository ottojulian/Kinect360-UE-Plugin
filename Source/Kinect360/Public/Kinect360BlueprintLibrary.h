#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kinect360Types.h"
#include "Kinect360BlueprintLibrary.generated.h"

UCLASS()
class KINECT360_API UKinect360BlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "Kinect360")
    static bool IsSupported();

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static bool StartSensor();

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static void StopSensor();

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static TArray<FKinect360SkeletonFrame> PollSkeletons();
};
