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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	ACourseSpline* CourseSplineActor = NULL;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> TrackGateArray;

};



