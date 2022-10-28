// Shoot Them Up Game


#include "UI/STUPlayerStateRollWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void USTUPlayerStateRollWidget::SetPlayerName(const FText& Text)
{
	if (!PlayerNameTextBlock) return;
	PlayerNameTextBlock->SetText(Text);

}
void USTUPlayerStateRollWidget::SetKills(const FText& Text)
{
	if (!KillsTextBlock) return;
	KillsTextBlock->SetText(Text);

}
void USTUPlayerStateRollWidget::SetDeaths(const FText& Text)
{
	if (!DeathTextBlock) return;
	DeathTextBlock->SetText(Text);

}
void USTUPlayerStateRollWidget::SetTeams(const FText& Text)
{
	if (!TeamTextBlock) return;
	TeamTextBlock->SetText(Text);

}
void USTUPlayerStateRollWidget::SetPlayerIndicatorVisibility(bool Visible)
{
	if (!PlayerIndicatorImage) return;
	PlayerIndicatorImage->SetVisibility(Visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);

}