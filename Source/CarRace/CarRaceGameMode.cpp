// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceGameMode.h"
#include "CarRacePlayerController.h"

ACarRaceGameMode::ACarRaceGameMode()
{
	PlayerControllerClass = ACarRacePlayerController::StaticClass();
}

// Called when the game starts or when spawned
void ACarRaceGameMode::BeginPlay()
{
	Super::BeginPlay();

	// CourseSplineに沿ってTrackGateにインデックス付与
	TArray<AActor*> SplineActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACourseSpline::StaticClass(), SplineActors);
	if (SplineActors.IsEmpty()) {
		UE_LOG(LogTemp, Warning, TEXT("There is no CourseSpline"));
		return;
	}
	ACourseSpline* CourseSplineActor = Cast<ACourseSpline>(SplineActors[0]);
	if (CourseSplineActor) {
		USplineComponent* CourseSplineComp = CourseSplineActor->SplineComp;
		if (CourseSplineComp) {
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrackGate::StaticClass(), TrackGateArray);
			int32 TrackGateCount = TrackGateArray.Num();

			TrackGateArray.Sort([CourseSplineComp](const AActor& GateA, const AActor& GateB) {
				float KeyA = CourseSplineComp->FindInputKeyClosestToWorldLocation(GateA.GetActorLocation());
				float KeyB = CourseSplineComp->FindInputKeyClosestToWorldLocation(GateB.GetActorLocation());
				float DistA = CourseSplineComp->GetDistanceAlongSplineAtSplineInputKey(KeyA);
				float DistB = CourseSplineComp->GetDistanceAlongSplineAtSplineInputKey(KeyB);

				return DistA < DistB;
			});

			for (int32 i = 0; i < TrackGateCount; i++) {
				ATrackGate* Gate = Cast<ATrackGate>(TrackGateArray[i]);
				if (Gate) {
					Gate->SetGateIndex(i);
					Gate->SetGateCount(TrackGateCount);
					Gate->MaxLap = 1;
					if (i == 0) {
						Gate->SetIsFinieshGate(true);
					}
				}
			}
		}
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController) {
		ScreenMessageWidget = CreateWidget<UScreenMessage>(PlayerController, ScreenMessageClass);
		if (ScreenMessageWidget) {
			ScreenMessageWidget->AddToPlayerScreen();
			ScreenMessageWidget->SetMessageText("Get Ready?");
		}
	}

	CountdownSeconds = CountdownDelay;
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACarRaceGameMode::OnCountdownTimerTimeout, 1.0f, true);
	

	// BGM
	UGameplayStatics::PlaySound2D(
		GetWorld(),
		RaceBGM
	);

}

// Called every frame
void ACarRaceGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarRaceGameMode::OnCountdownTimerTimeout()
{
	if (CountdownSeconds > 0) {
		ScreenMessageWidget->SetMessageText(FString::FromInt(CountdownSeconds));
	}
	else if (CountdownSeconds == 0) {
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController) {
			ACarRacePawn *Car = Cast<ACarRacePawn>(PlayerController->GetPawn());
			if (Car) {
				Car->SetStartedFlg(true);
			}
		}

		ScreenMessageWidget->SetMessageText("Get Ready?");
	}
	else {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		ScreenMessageWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	CountdownSeconds--;
}