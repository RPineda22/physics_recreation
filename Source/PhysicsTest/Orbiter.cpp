// Fill out your copyright notice in the Description page of Project Settings.


#include "Orbiter.h"

// Sets default values
AOrbiter::AOrbiter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));

	//mesh->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AOrbiter::BeginPlay()
{
	Super::BeginPlay();
	speed = 0.5;

	range = 15;
	
}

// Called every frame
void AOrbiter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Orbit();

}

void AOrbiter::Orbit()
{
	SetActorRelativeLocation(GetActorLocation() + (speed * GetActorRightVector() * range));
	SetActorRelativeRotation(GetActorRotation() + FRotator(0,speed,0));
}

