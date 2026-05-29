// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "CarRacePlayerController.h"

ACarRaceGameMode::ACarRaceGameMode()
{
	PlayerControllerClass = ACarRacePlayerController::StaticClass();

	USplineComponent* CourseSplineComp = CourseSpline->SplineComp;
	if (CourseSplineComp) {
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrackGate::StaticClass(), TrackGateArray);
		int32 TrackGateCount = TrackGateArray.Num();

		// CourseSplineに沿ってTrackGateにインデックス付与
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
			}
		}
	}


}
