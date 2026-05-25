// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceGameMode.h"
#include "CarRacePlayerController.h"

ACarRaceGameMode::ACarRaceGameMode()
{
	PlayerControllerClass = ACarRacePlayerController::StaticClass();
}
