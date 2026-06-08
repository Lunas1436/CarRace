// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackGate.h"
#include "CarRaceGameMode.h"

// Sets default values
ATrackGate::ATrackGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	CollisionBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBoxComp"));
	CollisionBoxComp->SetupAttachment(RootComp);
	CollisionBoxComp->SetBoxExtent(FVector(1000.0f));
	CollisionBoxComp->SetLineThickness(32.0f);
	CollisionBoxComp->bHiddenInGame = false;
	CollisionBoxComp->SetCollisionProfileName(FName("OverlapAllDynamic"));

}

// Called when the game starts or when spawned
void ATrackGate::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ATrackGate::OnOverlapBegin);
}

// Called every frame
void ATrackGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrackGate::SetGateIndex(int32 Index)
{
	GateIndex = Index;
}

int32 ATrackGate::GetGateIndex()
{
	return GateIndex;
}

void ATrackGate::SetGateCount(int32 Count)
{
	GateCount = Count;
}

int32 ATrackGate::GetGateCount()
{
	return GateCount;
}

void ATrackGate::SetIsFinieshGate(bool bFlg)
{
	bIsFinishGate = bFlg;
}

// ゲート通過
void ATrackGate::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this) {
		ACarRacePawn* CarPawn = Cast<ACarRacePawn>(OtherActor);
		if (CarPawn) {
			// ゲートインデックス判定
			int32 CarPawnGateIndex = CarPawn->GetCurrentGateIndex();
			if (CarPawnGateIndex == GateIndex && GateCount > 0) { // 通過OK
				CarPawnGateIndex = (CarPawnGateIndex + 1) % GateCount;
				CarPawn->SetCurrentGateIndex(CarPawnGateIndex);

				// ラップ処理
				if (bIsFinishGate) {
					ProcessLapCount(CarPawn);
				}	
			}
			else if(CarPawnGateIndex > GateIndex) { // 正しいコースに戻るように指示
				UE_LOG(LogTemp, Display, TEXT("Go back to the CORRECT GATE"));
			}
		}
	}
}

// ラップ処理
void ATrackGate::ProcessLapCount(ACarRacePawn* OtherActor)
{
	int32 CarPawnLapCount = OtherActor->GetCurrentLapCount();
	CarPawnLapCount++;
	if (CarPawnLapCount > MaxLap) {
		// ゴール
		ProcessRaceFinish();
	}

	OtherActor->SetCurrentLapCount(CarPawnLapCount);
}

// ゴール判定
void ATrackGate::ProcessRaceFinish()
{
	AGameModeBase *GameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (GameMode) {
		ACarRaceGameMode* CRGameMode = Cast<ACarRaceGameMode>(GameMode);
		if (CRGameMode) {
			CRGameMode->OnRaceFinish();
		}
	}
}






