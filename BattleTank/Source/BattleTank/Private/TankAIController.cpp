// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
   Super::BeginPlay();
   auto MyTank = GetControlledTank();

   if (!MyTank)
   {
      UE_LOG(LogTemp, Warning, TEXT("TankAIController: I Don't Control a Tank!"));
   }
   else
   {
      UE_LOG(LogTemp, Warning, TEXT("TankAIController: I Control Tank: %s"), *MyTank->GetName());
   }
}



