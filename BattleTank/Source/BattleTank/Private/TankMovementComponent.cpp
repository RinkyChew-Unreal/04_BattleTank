// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
   LeftTrack = LeftTrackToSet;
   RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
   if (!LeftTrack || !RightTrack) { return; }
   LeftTrack->SetThrottle(Throw);
   RightTrack->SetThrottle(Throw);

   //TODO prevent double-speed due to dual control use
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
   if (!LeftTrack || !RightTrack) { return; }
   LeftTrack->SetThrottle(Throw);
   RightTrack->SetThrottle(-Throw);

   //TODO prevent double-speed due to dual control use
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
   //no need to call Super as we're replacing the functionality of the method
   auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
   auto AIForwardIntention = MoveVelocity.GetSafeNormal();
   IntendMoveForward(FVector::DotProduct(TankForward, AIForwardIntention));
   //auto Name = GetOwner()->GetName();
   //UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to: %s"), *Name, *AIForwardIntention.ToString());
}

