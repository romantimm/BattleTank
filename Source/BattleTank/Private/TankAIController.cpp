// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn);
}


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();


	auto AIControlledTank = GetControllerTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controller couldn't find tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controlling Tank: %s and found Player Tank %s"), *(AIControlledTank->GetName()), *(GetPlayerTank()->GetName()))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto HumanPlayerTank = GetPlayerTank();
	if (HumanPlayerTank)
	{
		// Move Towards the player
		// Aim at towards the player
		GetControllerTank()->AimAt(HumanPlayerTank->GetActorLocation());
		// Fire if ready
	}
}