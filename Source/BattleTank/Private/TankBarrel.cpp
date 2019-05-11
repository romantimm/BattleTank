// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	//move the barrel the right amound this frame


	//given a max elevation SPEED, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationCHange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationCHange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegress, MaxElevationDegress);
	
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}