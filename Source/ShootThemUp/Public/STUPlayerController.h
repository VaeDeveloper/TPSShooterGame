// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUCoreTypes.h"
#include "STUPlayerController.generated.h"

class USTURespawnComponent;
class USoundCue;

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ASTUPlayerController();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	USTURespawnComponent* RespawnComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* MusicSound;

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

private:
	void OnPausedGame();
	void OnMatchStateChanged(ESTUMatchState State);


};
