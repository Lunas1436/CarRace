// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceResult.h"
#include "Kismet/GameplayStatics.h"

void URaceResult::NativeConstruct()
{
	if (Btn_QuitGame) {
		Btn_QuitGame->OnClicked.AddDynamic(this, &URaceResult::OnGameQuitButtonClicked);
	}
	if (Btn_NextCourse) {
		Btn_NextCourse->OnClicked.AddDynamic(this, &URaceResult::OnNextCourseButtonClicked);
	}
}

void URaceResult::OnGameQuitButtonClicked()
{
	// 確認用
	FName TitleMenuMap = FName("TitleMap");
	UGameplayStatics::OpenLevel(GetWorld(), TitleMenuMap);
}

void URaceResult::OnNextCourseButtonClicked()
{
	// ゲームインスタンスからコースインデックスを取得する

}

void URaceResult::SetRecordText(FText Record)
{
	RecordText->SetText(Record);
}
