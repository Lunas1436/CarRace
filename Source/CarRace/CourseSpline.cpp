// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseSpline.h"

// Sets default values
ACourseSpline::ACourseSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComp = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	SetRootComponent(SplineComp);

}

// Called when the game starts or when spawned
void ACourseSpline::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACourseSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

