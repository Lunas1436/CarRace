// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ScreenMessage.h"
#include "CourseSpline.h"
#include "TrackGate.h"
#include "CarRaceUI.h"
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

	void OnCountdownTimerTimeout();
	void OnCountElapsedTimer();
	void OnRaceFinish();

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UScreenMessage> ScreenMessageClass;

	UScreenMessage* ScreenMessageWidget;

	UPROPERTY(EditAnywhere)
	int32 CountdownDelay = 7;

	int32 CountdownSeconds;
	FTimerHandle CountdownTimerHandle;

	float StartTime = 0.0f;
	FTimerHandle ElapsedTimerHandle;
	UCarRaceUI* RaceTime;

	// サウンド
	// レース中のBGMサウンド
	UPROPERTY(EditAnywhere)
	USoundBase* RaceBGM;

	// カウントダウンサウンド
	UPROPERTY(EditAnywhere)
	USoundBase* CountdownCountSound;

	UPROPERTY(EditAnywhere)
	USoundBase* CountdownStartSound;
	

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> TrackGateArray;



};



