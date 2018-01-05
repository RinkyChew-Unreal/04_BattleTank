// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"



UTankTrack::UTankTrack()
{
   PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
   Super::BeginPlay();
   OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
   Super::TickComponent(DeltaTime,TickType,ThisTickFunction);

   //calculate the slippage speed (DotProduct)
   auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

   //work-out the required acceleration this frame to correct
   auto CorrectionAcceleration = SlippageSpeed / DeltaTime * -GetRightVector(); //speed/time

   //calculate and apply sideways force (F = m * a) per track
   auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
   auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
   TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponenet, FVector NormalImpulse, const FHitResult & Hit)
{
   auto Time = GetWorld()->GetTimeSeconds();
   auto Tank = GetOwner()->GetName();
   UE_LOG(LogTemp, Warning, TEXT("%f Tank: %s - I'M HIT!!"), Time, *Tank);
}

void UTankTrack::SetThrottle(float Throttle)
{
   auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
   auto ForceLocation = GetComponentLocation();
   auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
   TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);	
}