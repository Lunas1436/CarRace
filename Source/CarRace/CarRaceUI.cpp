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

void UCarRaceUI::UpdateTimer(float ElapsedTime)
{
	OnTimerUpdate(ElapsedTime);
}

void UCarRaceUI::OnTimerUpdate(float ElapsedTime)
{
	int32 Minutes = ElapsedTime / 60;
	int32 Seconds = (int32)ElapsedTime % 60;
	int32 Milli = (ElapsedTime - (int32)ElapsedTime) * 1000;

	FString UpdateTime = FString::Printf(
		TEXT("%02d:%02d:%03d"),
		Minutes,
		Seconds,
		Milli
	);

	TimerText->SetText(FText::FromString(UpdateTime));
}


