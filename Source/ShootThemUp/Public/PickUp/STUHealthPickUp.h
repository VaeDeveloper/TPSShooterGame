// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "PickUp/STUBasePickUp.h"
#include "STUHealthPickUp.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUHealthPickUp : public ASTUBasePickUp
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
	float HealthAmount = 100.0f;

private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
	
};
