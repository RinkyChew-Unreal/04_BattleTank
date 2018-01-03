// Copyright RinkyChew LLC

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

// Depends on MovementComponent via pathfinding system

void ATankAIController::BeginPlay()
{
   Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   auto ControlledTank = GetPawn();
   auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

   if (!ensure(PlayerTank && ControlledTank)) { return; }
   //move towards the player
   MoveToActor(PlayerTank, AcceptanceRadius);

   //Aim towards the player
   auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
   AimingComponent->AimAt(PlayerTank->GetActorLocation());
    
   //TODO fix firing
   AimingComponent->Fire();
}
