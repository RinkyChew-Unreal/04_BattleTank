// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

//Forward Declaration
class ATank;
class UTankMovementComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
   GENERATED_BODY()
   
private:
   virtual void BeginPlay() override;

   virtual void Tick(float DeltaTime) override;

   //how close can the AI tank get
   float AcceptanceRadius = 3000;

public:
};
