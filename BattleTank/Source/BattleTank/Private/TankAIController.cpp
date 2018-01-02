// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

// Depends on MovementComponent via pathfinding system

void ATankAIController::BeginPlay()
{
   Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   auto AITank = Cast<ATank>(GetPawn());
   auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

   if (ensure(PlayerTank))
   {

      //move towards the player
      MoveToActor(PlayerTank, AcceptanceRadius);

      //Aim towards the player
      AITank->AimAt(PlayerTank->GetActorLocation());
    
      AITank->Fire();
   }
}
