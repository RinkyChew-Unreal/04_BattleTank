// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
   GENERATED_BODY()
   
public:
   //-1 is max downward speed and +1 is max upward speed
   void Elevate(float RelativeSpeed);
   
private:
   UPROPERTY(EditAnywhere, Category = Setup)
   float MaxDegreesPerSecond = 35.0f;  

   UPROPERTY(EditAnywhere, Category = Setup)
   float MinElevation = -2.5f;  

   UPROPERTY(EditAnywhere, Category = Setup)
   float MaxElevation = 25.0f;  

};
