// Copyright RinkyChew LLC

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
   Reloading,
   Aiming,
   Locked
};

//forward declaration
class UTankBarrel;   
class UTankTurret;

//holds Barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
   GENERATED_BODY()

public:	
   UFUNCTION(BlueprintCallable, Category = "Setup")
   void Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

   void AimAt(FVector HitLocation);

protected:
   UPROPERTY(BlueprintReadOnly, Category = "State")
   EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
   // Sets default values for this component's properties
   UTankAimingComponent();

   UTankBarrel* Barrel = nullptr;
   UTankTurret* Turret = nullptr;

   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float LaunchSpeed = 4000.0f;

   void MoveBarrelTowards(FVector AimDireection);
};
