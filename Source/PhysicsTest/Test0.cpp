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

	accelerationDuration = 4.0;

	index = 0;
	stageOfProgram = 1;
}

void ATest0::setFPS(float _fps)
{
	fps = _fps;
}

float ATest0::getFPS()
{
	return fps;
}



// Expects seconds and returns the number of substeps based on fps
int ATest0::getSubsteps(float total_seconds)
{
	// this numer should be either the tick rate or delta seconds
	float substeps_length = 1.0 / getFPS();

	UE_LOG(LogTemp, Warning, TEXT("Substeps length: %f"), substeps_length);
	// Calculates the number of substeps, however, it contains decimal values that need to be substracted
	float n_substeps = total_seconds / substeps_length;

	// Substracting the decimal values from n_substeps so we can convert to int without truncating or rounding
	float remainder = fmod(n_substeps, 1);


	int total_substeps = n_substeps - remainder;

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
TArray<FVector> ATest0::setAccelerationOverTime(float _acceleration, float _seconds, float substep_length)
{
	// Calculate the length of our array (how many substeps we need)
	int substeps = getSubsteps(_seconds);
	TArray<FVector>myArray;
	float n = substep_length;

	for (int i = 0; i < substeps; i++) {
		//UE_LOG(LogTemp, Warning, TEXT("N value is : %f"), n);
		// getting actor current position 
		FVector currentLocation = ATest0::GetActorLocation();

		// getting actor Forward Vector
		FVector forwardV = ATest0::GetActorForwardVector();

		// Getting vector values and applying acceleration
		float xValue = GetActorForwardVector().X;
		//UE_LOG(LogTemp, Warning, TEXT("X Value: %f"), xValue);

		float new_x = (1.0 / 2.0) * _acceleration * xValue * pow(n, 2);


		float yValue = GetActorForwardVector().Y;
		//UE_LOG(LogTemp, Warning, TEXT("Y Value: %f"), yValue);


		float new_y = (1.0 / 2.0) * _acceleration * yValue * pow(n, 2);
		//UE_LOG(LogTemp, Warning, TEXT("New Y Value: %f"), new_y);


		float zValue = GetActorForwardVector().Z;
		float new_z = (1.0 / 2.0) * _acceleration * zValue * pow(n, 2);


		FVector newLocation = FVector(new_x, new_y, new_z);
		myArray.Add(newLocation);


		//UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, X: %f"), new_x);
		//UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, y: %f"), new_y);
		//UE_LOG(LogTemp, Warning, TEXT("After applying acceleration, z: %f"), new_z);


		n += substep_length;
		//UE_LOG(LogTemp, Warning, TEXT("N value is : %f"), n);
	}

	return myArray;

}

// Called when the game starts or when spawned
void ATest0::BeginPlay()
{
	Super::BeginPlay();

	// calculating Acceleration
	acceleration = calculateAcceleration(mass, force);

	
}

// Called every frame
void ATest0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	// getting array of acceleration over time
	if (stageOfProgram == 1) 
	{
		float temp_fps = 1.0f / DeltaTime;
		float substep_length = DeltaTime;

		// Substracting the decimal values from n_substeps so we can convert to int without truncating or rounding
		float remainder = fmod(temp_fps, 1);


		int new_fps = temp_fps - remainder;

		setFPS(new_fps);
	



		numOfStepsToCalculate = getSubsteps(accelerationDuration);
	
		UE_LOG(LogTemp, Warning, TEXT("Number of substeps: %d "), numOfStepsToCalculate);

		accelerationDuration = 86400;
		all_locations = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations1 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations2 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations3 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations4 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations5 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations6 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations7 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations8 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations9 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations10 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations11 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations12 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations13 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations14 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations15 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations16 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations17 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations18 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations19 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations20 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations21 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations22 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);
		TArray<FVector> all_locations23 = setAccelerationOverTime(acceleration, accelerationDuration, substep_length);


		stageOfProgram = 2;

		UE_LOG(LogTemp, Warning, TEXT("FPS: %d /s"), new_fps);
	}



	

	if (stageOfProgram == 2 && index < all_locations.Num())
	{
		FVector temp_vector = all_locations[index];
		SetActorLocation(temp_vector);
		index += 1;
	}
	

}

