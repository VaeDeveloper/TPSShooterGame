// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "PickUp/STUBasePickUp.h"
#include "STUAmmoPickUp.generated.h"


class ASTUBaseWeapon;

UCLASS()
class SHOOTTHEMUP_API ASTUAmmoPickUp : public ASTUBasePickUp
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "10.0"))
		int32 ClipsAmount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
		TSubclassOf<ASTUBaseWeapon> WeaponType;


private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;


	
};
