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
class AProjectile;

//holds Barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
   GENERATED_BODY()

public:	
   UFUNCTION(BlueprintCallable, Category = "Setup")
   void Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

   UFUNCTION(BlueprintCallable, Category = "Firing")
   void Fire();

   void AimAt(FVector HitLocation);

protected:
   UPROPERTY(BlueprintReadOnly, Category = "State")
   EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
   // Sets default values for this component's properties
   UTankAimingComponent();

   virtual void BeginPlay() override;

   virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
   
   void MoveBarrelTowards(FVector AimDireection);

   UPROPERTY(EditDefaultsOnly, Category = "Setup")
   TSubclassOf<AProjectile> ProjectileBlueprint;

   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float LaunchSpeed = 4000.0f;

   UTankBarrel* Barrel = nullptr;
   UTankTurret* Turret = nullptr;

   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float ReloadTimeInSeconds = 3.0f;

   float LastFireTime = 0.0f;

};
