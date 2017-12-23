// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const 
{
   return Cast<ATank>(GetPawn());
}

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
