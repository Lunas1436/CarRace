// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CarRacePawn.h"
#include "CarRaceSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class ACarRaceSportsCar : public ACarRacePawn
{
	GENERATED_BODY()
	
public:

	ACarRaceSportsCar();

public:
	UPROPERTY(VisibleAnywhere)
	int32 NextGateIndex = 0;

};
