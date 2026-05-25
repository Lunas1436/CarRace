// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCarRaceWheelRear::UCarRaceWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}