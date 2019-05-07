// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank/BattleTank.h"


ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller isn't possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player controller here with %s!"), *(ControlledTank->GetName()));
	}
}
	
