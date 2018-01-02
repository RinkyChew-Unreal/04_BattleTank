// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  //the *.generated.h must be the last include

//Forward Declaration
class ATank;
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

protected:
   UFUNCTION(BlueprintCallable, Category = "Setup")
      ATank* GetControlledTank() const;

private:
   //start the tank moving the barrel so that a shot would hit where
   //the crosshair intersects the world
   void AimTowardsCrosshair();

   //return and out parameter, returns true if hits landscape
   bool GetSightRayHitLocation(FVector & OutHitLocation) const;

   bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;

   bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

   UPROPERTY(EditDefaultsOnly)
   float CrosshairXLocation = 0.5f;

   UPROPERTY(EditDefaultsOnly)
   float CrosshairYLocation = 0.3333f;

   UPROPERTY(EditDefaultsOnly)
   float LineTraceRange = 1000000.0f;

};
