// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
   Super::BeginPlay();
   auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
   if (AimingComponent)
   {
      FoundAimingComponent(AimingComponent);
   }
   else
   {
      UE_LOG(LogTemp, Warning, TEXT("PlayerController::BeginPlay can't find the AimingComponent!"));
   }
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
   Super::Tick(DeltaSeconds);
   AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
   if (!GetControlledTank()) { return; }

   FVector HitLocation; //out parameter

   //get world location of line-trace through the crosshair
   if (GetSightRayHitLocation(HitLocation))  //has a "side-effect", is going to line-trace
   {
      //TODO Tell controlled tank to aim at this point
      GetControlledTank()->AimAt(HitLocation);
   }
}

//get world location of line-trace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
   //find the crosshair position in pixel coordinates
   int32 ViewportSizeX, ViewportSizeY;
   GetViewportSize(ViewportSizeX, ViewportSizeY);
   auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
   FVector LookDirection;
   //de-project the screen position of the crosshair to a world direction
   if (GetLookDirection(ScreenLocation, LookDirection))
   {
      //line-trace along that LookDirection, and see what we hit (up to a max range)
      GetLookVectorHitLocation(LookDirection, OutHitLocation);   //Changed to return this IAW section 141 ? answer
   }

   return true;  //Changed from true IAW section 141 ? answer - This keeps barrel at angle of last good solution
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
   FHitResult HitResult;
   auto StartLocation = PlayerCameraManager->GetCameraLocation();
   auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
   if (GetWorld()->LineTraceSingleByChannel
      (
         HitResult,
         StartLocation,
         EndLocation,
         ECollisionChannel::ECC_Visibility
      )
   )
   {
      //set the location
      OutHitLocation = HitResult.Location;

      return true;
   }
   OutHitLocation = FVector(0.0f);
   return false;  //line trace didn't succeed
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
   FVector CameraWorldLocation;  //to be discarded...(req'd by method)
   return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
