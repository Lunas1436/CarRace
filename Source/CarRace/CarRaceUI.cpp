// Copyright Epic Games, Inc. All Rights Reserved.


#include "CarRaceUI.h"

void UCarRaceUI::UpdateSpeed(float NewSpeed)
{
	// format the speed to KPH or MPH
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	// call the Blueprint handler
	OnSpeedUpdate(FormattedSpeed);
}

void UCarRaceUI::UpdateGear(int32 NewGear)
{
	// call the Blueprint handler
	OnGearUpdate(NewGear);
}

void UCarRaceUI::UpdateElapsedTimer(FText ElapsedTime)
{
	OnElapsedTimerUpdate(ElapsedTime);
}

void UCarRaceUI::OnElapsedTimerUpdate(FText ElapsedTime)
{
	if (TimerText) {
		TimerText->SetText(ElapsedTime);
	}
}

void UCarRaceUI::SetTimerTextVisibility(bool bVisible)
{
	if (bVisible) {
		TimerText->SetVisibility(ESlateVisibility::Visible);
	}
	else {
		TimerText->SetVisibility(ESlateVisibility::Hidden);
	}
}


