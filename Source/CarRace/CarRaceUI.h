// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CarRaceUI.generated.h"

/**
 *  Simple Vehicle HUD class
 *  Displays the current speed and gear.
 *  Widget setup is handled in a Blueprint subclass.
 */
UCLASS(abstract)
class UCarRaceUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	/** Controls the display of speed in Km/h or MPH */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle")
	bool bIsMPH = false;

public:

	/** Called to update the speed display */
	void UpdateSpeed(float NewSpeed);

	/** Called to update the gear display */
	void UpdateGear(int32 NewGear);

	void UpdateTimer(float ElapsedTime);

protected:

	/** Implemented in Blueprint to display the new speed */
	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnSpeedUpdate(float NewSpeed);

	/** Implemented in Blueprint to display the new gear */
	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnGearUpdate(int32 NewGear);

	
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle")
	void OnTimerUpdate(float ElapsedTime);

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* TimerText;

};
