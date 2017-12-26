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
   void Elevate(float DegreesPerSecond);
   
private:
   UPROPERTY(EditAnywhere, Category = Setup)
   float MaxDegreesPerSecond = 35.0f;  

   UPROPERTY(EditAnywhere, Category = Setup)
   float MinElevation = -2.5f;  

   UPROPERTY(EditAnywhere, Category = Setup)
   float MaxElevation = 25.0f;  

};
