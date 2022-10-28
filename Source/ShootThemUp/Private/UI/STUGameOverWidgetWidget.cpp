// Shoot Them Up Game


#include "UI/STUGameOverWidgetWidget.h"
#include "STUGameModeBase.h"
#include "STUPlayerState.h"
#include "UI/STUPlayerStateRollWidget.h"
#include "Components/VerticalBox.h"
#include "STUUtils.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


void USTUGameOverWidgetWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GetWorld())
	{
		const auto  GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OneMatchStateChanged.AddUObject(this, &USTUGameOverWidgetWidget::OnMatchStateChanged);
		}
	}

	if (ResetLevelButton)
	{
		ResetLevelButton->OnClicked.AddDynamic(this, &USTUGameOverWidgetWidget::OnResetLevel);
	}
}

void USTUGameOverWidgetWidget::OnMatchStateChanged(ESTUMatchState State)
{
	if (State == ESTUMatchState::GameOver)
	{
		UpdatePlayerState();
	}
}
void USTUGameOverWidgetWidget::UpdatePlayerState()
{
	if (!GetWorld() || !PlayerStateBox) return;

	PlayerStateBox->ClearChildren();

	for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
	{
		const auto Controller = It->Get();
		if (!Controller) continue;

		const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);
		if (!PlayerState) continue;

		const auto PlayerStateRollWidget = CreateWidget<USTUPlayerStateRollWidget>(GetWorld(), PlayerStateRollWidgetClass);
		if (!PlayerStateRollWidget) continue;

		PlayerStateRollWidget->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
		PlayerStateRollWidget->SetKills(STUUtils::TextFromInt(PlayerState->GetKillsNum()));
		PlayerStateRollWidget->SetDeaths(STUUtils::TextFromInt(PlayerState->GetDeathNum()));
		PlayerStateRollWidget->SetTeams(STUUtils::TextFromInt(PlayerState->GetTeamID()));
		PlayerStateRollWidget->SetPlayerIndicatorVisibility(Controller->IsPlayerController());

		PlayerStateBox->AddChild(PlayerStateRollWidget);

	}
}

void USTUGameOverWidgetWidget::OnResetLevel()
{
	//const FName CurrentLevelName = "TestLevel";
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}