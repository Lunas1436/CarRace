// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CourseSpline.h"
#include "TrackGate.h"
#include "CarRaceGameMode.generated.h"

UCLASS(abstract)
class CARRACE_API ACarRaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACarRaceGameMode();
};



