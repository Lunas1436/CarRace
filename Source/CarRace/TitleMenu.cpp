// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleMenu.h"
#include "Kismet/GameplayStatics.h"

void UTitleMenu::NativeConstruct()
{
	if (Btn_GameStart) {
		Btn_GameStart->OnClicked.AddDynamic(this, &UTitleMenu::OnGameStartButtonClicked);
	}


}

void UTitleMenu::OnGameStartButtonClicked()
{
	FString Currentlvl = GetWorld()->GetName();
	//FString Nextlvl = TEXT("Course1");
	FName Nextlvl = FName("Course1");
	UE_LOG(LogTemp, Display, TEXT("lvlname %s"), *Currentlvl);
	UGameplayStatics::OpenLevel(GetWorld(), Nextlvl);
}
