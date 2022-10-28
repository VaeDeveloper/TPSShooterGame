// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "STUBaseCharacter.h"
#include "Teleport.generated.h"


class USoundCue;

UCLASS()
class SHOOTTHEMUP_API ATeleport : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:
	ATeleport();

	UFUNCTION()
	void EnterTeleportBox(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void EndTeleportBox(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Teleport")
	ATeleport* OtherTeleport;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* EnterSound;




	UPROPERTY()
	bool bTeleporting;
	
};
