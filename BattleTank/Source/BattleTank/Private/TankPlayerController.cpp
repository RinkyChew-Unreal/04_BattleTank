// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
   Super::BeginPlay();
   auto MyTank = GetControlledTank();

   if (!MyTank) 
   {
      UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: I Don't Control a Tank!"));
   }
   else
   {
      UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: I Control Tank: %s"), *MyTank->GetName());
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
      UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
         //TODO Tell controlled tank to aim at this point
   }
}

//get world location of line-trace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
   OutHitLocation = FVector(1.0f);
   return true;
}
