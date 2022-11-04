// Fill out your copyright notice in the Description page of Project Settings.


#include "Test0.h"
#include <cmath>

// Sets default values
ATest0::ATest0()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Expects seconds and returns the number of 0.036s substeps
int ATest0::getSubsteps(float total_seconds)
{
	// this numer should be either the tick rate or delta seconds
	float substeps_length = 0.036;

	// Calculates the number of substeps, however, it contains decimal values that need to be substracted
	float n_substeps = total_seconds / substeps_length;
	UE_LOG(LogTemp, Warning, TEXT("N substeps before modulus: %f"), n_substeps);

	// Substracting the decimal values from n_substeps so we can convert to int without truncating or rounding
	float remainder = fmod(n_substeps, 1);
	UE_LOG(LogTemp, Warning, TEXT("Remainder: %f"), remainder);

	int total_substeps = n_substeps - remainder;

	UE_LOG(LogTemp, Warning, TEXT("Total substeps without decimal values %f"), total_substeps);

	return total_substeps;
}

// Calculates force. 1 unit is equivalent to 1 centinewton
float ATest0::calculateForce(float _mass, float _acceleration)
{
	float force = _mass * _acceleration;
	return force;
}
// Called when the game starts or when spawned
void ATest0::BeginPlay()
{
	Super::BeginPlay();

	//testing getSubsteps function
	float seconds = 4.0;

	int loop_length = getSubsteps(seconds);

	UE_LOG(LogTemp, Warning, TEXT("Amount of substeps: %d"), loop_length);
	
}

// Called every frame
void ATest0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

