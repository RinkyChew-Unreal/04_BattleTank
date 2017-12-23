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

   //UE_LOG(LogTemp, Warning, TEXT("PlayerController Tick..."));
}

ATank* ATankPlayerController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
   if (!GetControlledTank()) { return; }

   //get world location of line-trace through the crosshair
   //if it hits the landscape
      //Tell controlled tank to aim at this point

}
