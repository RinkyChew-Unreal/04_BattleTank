// Copyright RinkyChew LLC

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

//Forward Declarations


/**
 * Responsible for calling AI Tank Aiming
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
   GENERATED_BODY()
   
private:
   virtual void BeginPlay() override;

   virtual void Tick(float DeltaTime) override;

   //how close can the AI tank get
   float AcceptanceRadius = 3000;
};
