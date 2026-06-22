// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "CarRacePlayerController.h"
#include "CarRaceUI.h"

void ATitleGameMode::BeginPlay()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC) {
		ACarRacePlayerController* CarRacePC = Cast<ACarRacePlayerController>(PC);
		if (CarRacePC) {
			UCarRaceUI* RaceTime = CarRacePC->GetVehicleUI();
			if (RaceTime) {
				RaceTime->SetTimerTextVisibility(false);
			}
		}

		TitleMenuWidget = CreateWidget<UTitleMenu>(PC, TitleMenuClass);
		if (TitleMenuWidget) {
			TitleMenuWidget->AddToViewport();
			TitleMenuWidget->InitButton();
		}
	}

}
