// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
   Super::BeginPlay();
   auto MyTank = GetControlledTank();
   auto PlayerTank = GetPlayerTank();

   if (!PlayerTank)
   {
      UE_LOG(LogTemp, Warning, TEXT("TankAIController: I Can't Find the Player's Tank!"));
   }
   else
   {
      UE_LOG(LogTemp, Warning, TEXT("TankAIController: I Found the Player's Tank: %s"), *PlayerTank->GetName());
   }
}

ATank* ATankAIController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
   auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
   return Cast<ATank>(PlayerPawn);
}



