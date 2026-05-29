// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackGate.h"

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

void ATrackGate::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void ATrackGate::SetGateIndex(int32 Index)
{
	GateIndex = Index;
}

int32 ATrackGate::GetGateIndex()
{
	return GateIndex;
}




