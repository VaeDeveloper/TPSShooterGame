// Shoot Them Up Game


#include "PickUp/STUHealthPickUp.h"
#include "Components/STUHealthComponent.h"	
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);


bool ASTUHealthPickUp::GivePickupTo(APawn* PlayerPawn)
{

	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent) return false;

	return HealthComponent->TryToAddHealth(HealthAmount);
}