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

	// Expects seconds and returns the number of 0.036s substeps
	UFUNCTION(BlueprintCallable)
		int getSubsteps(float total_seconds);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
