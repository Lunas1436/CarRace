// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleMenu.h"
#include "Kismet/GameplayStatics.h"
#include "CarRacePlayerController.h"

void UTitleMenu::NativeConstruct()
{
	if (Btn_GameStart) {
		Btn_GameStart->OnClicked.AddDynamic(this, &UTitleMenu::OnGameStartButtonClicked);
		Btn_GameStart->IsFocusable = true;
		Btn_GameStart->SetKeyboardFocus();
	}

	APlayerController* PC = GetOwningPlayer();
	if (PC) {
		FInputModeUIOnly InputMode;
		InputMode.SetWidgetToFocus(TakeWidget());
		PC->SetInputMode(InputMode);
		PC->bShowMouseCursor = true;
	}
}

void UTitleMenu::OnGameStartButtonClicked()
{
	FString Currentlvl = GetWorld()->GetName();
	UE_LOG(LogTemp, Display, TEXT("lvlname %s"), *Currentlvl);
	FName Nextlvl = FName("Course1");
	UGameplayStatics::OpenLevel(GetWorld(), Nextlvl);
}
