// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ScreenMessage.generated.h"

/**
 * 
 */
UCLASS()
class CARRACE_API UScreenMessage : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetMessageText(FString Message);


public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* TextMessage;


	
};
