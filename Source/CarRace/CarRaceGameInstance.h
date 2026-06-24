// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CarRaceGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CARRACE_API UCarRaceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int32 LevelCount = 1;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentLevelIndex = 0;
	
};
