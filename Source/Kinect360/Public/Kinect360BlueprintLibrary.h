#pragma once

#include "CoreMinimal.h"
#include "Kinect360Types.h"
#include "Kinect360BlueprintLibrary.generated.h"

UCLASS()
class UKinect360BlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "Kinect360")
    static bool IsSupported();

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static void GetSensorStatus(EKinect360Status& OutStatus, FString& OutMessage);

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static bool StartSensor();

    UFUNCTION(BlueprintCallable, Category = "Kinect360")
    static void StopSensor();
};
