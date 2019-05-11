// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	
	void ElevateBarrel(float DegressPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegressPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegress = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegress = 0;
};
