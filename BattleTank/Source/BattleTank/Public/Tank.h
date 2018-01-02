// Copyright RinkyChew LLC

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
   GENERATED_BODY()

public:
   void AimAt(FVector HitLocation);

   UFUNCTION(BlueprintCallable, Category = "Firing")
   void Fire();

protected:
  UPROPERTY(BlueprintReadOnly)
   UTankAimingComponent* TankAimingComponent = nullptr;

private:
   // Sets default values for this pawn's properties
   ATank();

   // Called when the game starts or when spawned
   virtual void BeginPlay() override;

   UPROPERTY(EditDefaultsOnly, Category = "Setup")
   TSubclassOf<AProjectile> ProjectileBlueprint;

   //TODO remove once firing is moved to AimingComponent
   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float LaunchSpeed = 4000.0f;

   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float ReloadTimeInSeconds = 3.0f;

   //local Barrel reference for spawning a projectile
   UTankBarrel* Barrel = nullptr;   //TODO remove

   float LastFireTime = 0.0f;
};
