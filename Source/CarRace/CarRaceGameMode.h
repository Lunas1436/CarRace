// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TrackGate.h"
#include "CarRaceGameMode.generated.h"

UCLASS(abstract)
class CARRACE_API ACarRaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACarRaceGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	TArray<AActor*> TrackGateArray;

};



