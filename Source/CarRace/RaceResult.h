// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "RaceResult.generated.h"

/**
 * 
 */
UCLASS()
class CARRACE_API URaceResult : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnGameQuitButtonClicked();
	UFUNCTION()
	void OnNextCourseButtonClicked();

	void SetRecordText(FText Message);

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* ResultText;

	UPROPERTY(meta = (BindWidget))
	UButton* Btn_QuitGame;

	UPROPERTY(meta = (BindWidget))
	UButton* Btn_NextCourse;
	
};
