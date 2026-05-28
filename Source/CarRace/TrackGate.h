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


public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBoxComp;
	
	// 
	UPROPERTY(VisibleAnywhere, Category = "TrackGate")
	int32 nGateIndex = 0;

	// ÉSÅ[ÉãîªíËóp
	UPROPERTY(EditAnywhere, Category = "TrackGate")
	bool bIsFinishLine = false;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
