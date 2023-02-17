// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trutle.generated.h"

UCLASS()
class TASK2_API ATrutle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrutle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "FinishLine")
	FString FinishLineName;

	FVector EndLocation;

	FVector TutrtleVelocity = FVector(500, 0, 0);

	void MoveTurtle(float DeltaTime);
};
