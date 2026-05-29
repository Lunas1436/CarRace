// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackGate.h"

// Sets default values
ATrackGate::ATrackGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrackGate::BeginPlay()
{
	Super::BeginPlay();
	
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


