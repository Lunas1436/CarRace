// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CourseSpline.h"
#include "TrackGate.h"
#include "CarRaceGameMode.generated.h"

UCLASS(abstract)
class ACarRaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACarRaceGameMode();

public:
	UPROPERTY(EditAnywhere)
	ACourseSpline* CourseSpline = NULL;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> TrackGateArray;


};



