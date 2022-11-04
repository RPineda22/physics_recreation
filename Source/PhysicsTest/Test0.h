// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test0.generated.h"

UCLASS()
class PHYSICSTEST_API ATest0 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest0();

	/*
		Returns the number of substeps of a given length within n seconds.
		@param seconds.
		@return number of substeps.
	*/
	UFUNCTION(BlueprintCallable)
		int getSubsteps(float total_seconds);

	/*
		Returns the force based on given mass and acceleration.
		@param mass (in kg) and acceleration (in cm/s).
		@return force in centinewtons.
	*/
	UFUNCTION(BlueprintCallable)
		float calculateForce(float _mass, float _acceleration);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
