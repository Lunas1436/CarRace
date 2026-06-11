// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameMode.h"
#include "Kismet/GameplayStatics.h"

void ATitleGameMode::BeginPlay()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC) {
		TitleMenuWidget = CreateWidget<UTitleMenu>(PC, TitleMenuClass);
		if (TitleMenuWidget) {
			TitleMenuWidget->AddToViewport();
		}
	}

}
