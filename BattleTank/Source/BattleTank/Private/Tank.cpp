// Copyright RinkyChew LLC


#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
   // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
   PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
   Super::BeginPlay();  //required to BP BeginPlay() to be called to run!!!
   TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector HitLocation)
{
   if (!ensure(TankAimingComponent)) { return; }
   TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
   if (!ensure(Barrel)) { return; }
   auto Time = GetWorld()->GetTimeSeconds();
   bool bIsReloaded = (Time - LastFireTime) > ReloadTimeInSeconds;
   if (bIsReloaded)
   {
      //spawn a projectile at the socket location on the barrel
      auto Projectile = GetWorld()->SpawnActor<AProjectile>
         (
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
            );

      Projectile->LaunchProjectile(LaunchSpeed);

      LastFireTime = Time;
   }
}

