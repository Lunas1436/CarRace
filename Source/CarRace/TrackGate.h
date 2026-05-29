// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "TrackGate.generated.h"

UCLASS()
class CARRACE_API ATrackGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackGate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetGateIndex(int32 Index);
	int32 GetGateIndex();


public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBoxComp;
	
	// ゲートインデックス
	UPROPERTY(VisibleAnywhere, Category = "TrackGate")
	int32 GateIndex = 0;

	// ゴール判定用
	UPROPERTY(EditAnywhere, Category = "TrackGate")
	bool bIsFinishLine = false;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
