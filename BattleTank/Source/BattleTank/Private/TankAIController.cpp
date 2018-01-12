// Copyright RinkyChew LLC

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h" //so we can implement OnDeath

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
   Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
   Super::SetPawn(InPawn);
   if (InPawn)
   {
      auto PossessedTank = Cast<ATank>(InPawn);
      if (!ensure(PossessedTank)) { return; }   //TODO remove ensure if all is OK

      //subscribe our local method to the tank's Death event
      PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
   }
}

//our event handler
void ATankAIController::OnPossessedTankDeath()
{
   if (!ensure(GetPawn())) { return; } //TODO remove ensure if all is OK
   GetPawn()->DetachFromControllerPendingDestroy();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
   auto ControlledTank = GetPawn();

   if (!ensure(PlayerTank && ControlledTank)) { return; }   //TODO remove ensure if all is OK
   
   // Move towards the player
   MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

   // Aim towards the player
   auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
   AimingComponent->AimAt(PlayerTank->GetActorLocation());

   if (AimingComponent->GetFiringState() == EFiringState::Locked)
   {
      AimingComponent->Fire(); // TODO limit firing rate
   }
}
