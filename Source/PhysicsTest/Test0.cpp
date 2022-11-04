// Fill out your copyright notice in the Description page of Project Settings.


#include "Test0.h"
#include <cmath>

// Sets default values
ATest0::ATest0()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Centinewtons
	force = 1160.0;

	// Mass in KG
	mass = 20.0;

	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);




}

// Expects seconds and returns the number of 0.036s substeps
int ATest0::getSubsteps(float total_seconds)
{
	// this numer should be either the tick rate or delta seconds
	float substeps_length = 0.036;

	// Calculates the number of substeps, however, it contains decimal values that need to be substracted
	float n_substeps = total_seconds / substeps_length;

	//UE_LOG(LogTemp, Warning, TEXT("N substeps before modulus: %f"), n_substeps);

	// Substracting the decimal values from n_substeps so we can convert to int without truncating or rounding
	float remainder = fmod(n_substeps, 1);

	//UE_LOG(LogTemp, Warning, TEXT("Remainder: %f"), remainder);

	int total_substeps = n_substeps - remainder;

	//UE_LOG(LogTemp, Warning, TEXT("Total substeps without decimal values %f"), total_substeps);

	return total_substeps;
}

// Calculates force. 1 unit is equivalent to 1 centinewton
float ATest0::calculateForce(float _mass, float _acceleration)
{
	float _force = _mass * _acceleration;
	return _force;
}

/*
	Returns acceleration based on force (in centinewtons) and mass (kg).
	@param mass (in kg) and force (in centinewtons).
	@return acceleration in cm/s^2.
*/
float ATest0::calculateAcceleration(float _mass, float _force)
{
	float _acceleration = _force / _mass;

	return _acceleration;
}

/*
	Sets an array of vectors that represents acceleration and velocity at each substep of specified time.
	@param acceleration in cm/s^2, time in seconds.
	@returns none.
*/
TArray<FVector> ATest0::setAccelerationOverTime(float _acceleration, float _seconds)
{
	// Calculate the length of our array (how many substeps we need)
	int substeps = getSubsteps(_seconds);
	TArray<FVector>myArray;
	float n = 0.036;

	for (int i = 0; i < 2; i++) {

		// getting actor current position 
		FVector currentLocation = ATest0::GetActorLocation();

		// getting actor Forward Vector
		FVector forwardV = ATest0::GetActorForwardVector();

		//FVector normalizedForwardV = forwardV.operator- currentLocation;

		// Getting vector values and applying acceleration
		float xValue = GetActorForwardVector().X;
		//UE_LOG(LogTemp, Warning, TEXT("X Value: %f"), xValue);

		float new_x = (1 / 2) * _acceleration * xValue * pow(n, 2);


		float yValue = GetActorForwardVector().Y;
		float new_y = (1 / 2) * _acceleration * yValue * pow(n, 2);

		float zValue = GetActorForwardVector().Z;
		float new_z = (1 / 2) * _acceleration * zValue * pow(n, 2);


		FVector newLocation = FVector(new_x, new_y, new_z);

		//SetActorLocation(newLocation);

		UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, X: %f"), new_x);
		UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, y: %f"), new_y);
		UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, z: %f"), new_z);

		// calculating position after substep
		//FVector newPosition = (1 / 2) * _acceleration;

		n += n;
	}

	return myArray;

}

// Called when the game starts or when spawned
void ATest0::BeginPlay()
{
	Super::BeginPlay();

	//testing getSubsteps function
	float seconds = 4.0;

	int loop_length = getSubsteps(seconds);

	UE_LOG(LogTemp, Warning, TEXT("Amount of substeps: %d"), loop_length);

	// Testing acceleration function
	float my_acceleration = calculateAcceleration(mass, force);

	UE_LOG(LogTemp, Warning, TEXT("Acceleration: %f cm/s^2"), my_acceleration);

	setAccelerationOverTime(my_acceleration, seconds);
	
}

// Called every frame
void ATest0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

