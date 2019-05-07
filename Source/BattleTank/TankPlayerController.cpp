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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshairs();
}

void ATankPlayerController::AimTowardsCrosshairs()
{
	if (!GetControllerTank()) { return; }

	FVector OutHitLocation;
	if (GetSightHitLocation(OutHitLocation))
	{
		GetControllerTank()->AimAt(OutHitLocation);
	}


}

bool ATankPlayerController::GetSightHitLocation(FVector& OutHitLocation)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// Find Crosshair position in pixel coordinates (important for varying screen sizes)
	auto CHScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// De project the screen position of the CH to a world direction
	FVector CameraWorldLocation;
	FVector LookDirection;
	if (DeprojectScreenPositionToWorld(CHScreenLocation.X, CHScreenLocation.Y, CameraWorldLocation, LookDirection))
	{
		// Line trace along the WorldLocation
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}


	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LookRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;

}
