// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
   GENERATED_BODY()
   
public:
   //-1 is max downward speed and +1 is max upward speed
   void Elevate(float RelativeSpeed);
   
private:
   UPROPERTY(EditDefaultsOnly, Category = Setup)
   float MaxDegreesPerSecond = 10.0f;  

   UPROPERTY(EditDefaultsOnly, Category = Setup)
   float MinElevation = -2.5f;  

   UPROPERTY(EditDefaultsOnly, Category = Setup)
   float MaxElevation = 30.0f;  

};
