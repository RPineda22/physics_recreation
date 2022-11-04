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

	// Root component to hold the rest of elements together
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class UStaticMeshComponent* Mesh;

	// Using a default value for now
	UPROPERTY(EditAnywhere, Category = "Custom Physics")
		float force;

	// Using a default value for now
	UPROPERTY(EditAnywhere, Category = "Custom Physics")
		float mass;
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

	/*
		Returns acceleration based on force (in centinewtons) and mass (kg).
		@param mass (in kg) and force (in centinewtons).
		@return acceleration in cm/s^2.
	*/
	UFUNCTION(BlueprintCallable)
		float calculateAcceleration(float _mass, float _force);

	/*
		Sets an array of vectors that represents acceleration and velocity at each substep of specified time.
		@param acceleration in cm/s^2, time in seconds.
		@returns none.
	*/
	UFUNCTION(BlueprintCallable)
		TArray<FVector> setAccelerationOverTime(float _acceleration, float _seconds);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
