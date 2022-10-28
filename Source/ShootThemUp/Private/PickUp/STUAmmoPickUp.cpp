// Shoot Them Up Game


#include "PickUp/STUAmmoPickUp.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"


DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);


bool ASTUAmmoPickUp::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead()) return false;
	
	const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
	if (!WeaponComponent) return false;
	return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);



}
