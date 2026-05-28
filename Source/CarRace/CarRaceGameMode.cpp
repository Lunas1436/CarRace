// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceGameMode.h"
#include "Kismet\GameplayStatics.h"
#include "CarRacePlayerController.h"

ACarRaceGameMode::ACarRaceGameMode()
{
	PlayerControllerClass = ACarRacePlayerController::StaticClass();
}

void ACarRaceGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrackGate::StaticClass(), TrackGateArray);
	int GateCount = TrackGateArray.Num();
	for (int i = 0; i < GateCount; i++) {
		UE_LOG(LogTemp, Display, TEXT("GateIndex=%d"), i);
	}

}
