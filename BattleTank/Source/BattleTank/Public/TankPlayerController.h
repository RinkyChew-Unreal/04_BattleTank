// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  //the *.generated.h must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
   GENERATED_BODY()
   
public:
   virtual void BeginPlay() override;

   virtual void Tick(float DeltaSeconds) override;

private:
   ATank* GetControlledTank() const;

   //start the tank moving the barrel so that a shot would hit where
   //the crosshair intersects the world
   void AimTowardsCrosshair();

   //return and out parameter, returns true if hits landscape
   bool GetSightRayHitLocation(FVector & OutHitLocation) const;

   UPROPERTY(EditAnywhere)
   float CrosshairXLocation = 0.5f;

   UPROPERTY(EditAnywhere)
   float CrosshairYLocation = 0.3333f;

};
