// Shoot Them Up Game


#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "STUHealthComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Damage.h"



AActor* USTUAIPerceptionComponent::GetClosesEnemy() const 
{
	TArray<AActor*>PerciveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerciveActors);
	if (PerciveActors.Num() == 0)
	{
		GetCurrentlyPerceivedActors(UAISense_Damage::StaticClass(), PerciveActors);
		if (PerciveActors.Num() == 0) return nullptr;
		
	}

	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller) return nullptr;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return nullptr;

	float BestDistance = MAX_FLT;
	AActor* BestPawn = nullptr;

	for (const auto PerciveActor: PerciveActors)
	{
		const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PerciveActor);

		const auto PercivePawn = Cast<APawn>(PerciveActor);
		const auto AreEnemys = PercivePawn && STUUtils::AreEnemys(Controller, PercivePawn->Controller);

		if (HealthComponent && !HealthComponent->IsDead() && AreEnemys) 
		{
			const auto CurrentDistance = (PerciveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
			if (CurrentDistance < BestDistance)
			{
				BestDistance = CurrentDistance;
				BestPawn = PerciveActor;
			}
		}

	}
	return BestPawn;
}

