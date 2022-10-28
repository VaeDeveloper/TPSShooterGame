// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUGameOverWidgetWidget.generated.h"

class UVerticalBox;
class UButton;


UCLASS()
class SHOOTTHEMUP_API USTUGameOverWidgetWidget : public UUserWidget
{
	GENERATED_BODY()
	


protected:
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* PlayerStateBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> PlayerStateRollWidgetClass;

	UPROPERTY(meta = (BindWidget))
	UButton* ResetLevelButton;

	virtual void NativeOnInitialized() override;


private:
	void OnMatchStateChanged(ESTUMatchState State);
	void UpdatePlayerState();

	UFUNCTION()
	void OnResetLevel();

};
