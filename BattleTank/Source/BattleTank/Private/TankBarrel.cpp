// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
   //move the barrel the correct amount this frame
   //given a max elevation speed and the frame time
   //RelativeSpeed should be between -1 & 1
   RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
   auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
   auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

   auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
   SetRelativeRotation(FRotator(Elevation, 0, 0));
}