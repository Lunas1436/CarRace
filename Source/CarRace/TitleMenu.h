// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "TitleMenu.generated.h"

/**
 * 
 */
UCLASS()
class CARRACE_API UTitleMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void OnGameStartButtonClicked();

public:
	UPROPERTY(meta = (BindWidget))
	UButton* Btn_GameStart;
		

};
