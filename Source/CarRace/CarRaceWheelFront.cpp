// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRaceWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCarRaceWheelFront::UCarRaceWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}