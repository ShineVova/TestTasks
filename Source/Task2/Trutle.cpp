// Fill out your copyright notice in the Description page of Project Settings.

#include "Trutle.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATrutle::ATrutle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATrutle::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor *> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), FoundActors);
	for (AActor *Actor : FoundActors)
	{
		if (Actor->GetName() == FinishLineName)
		{
			EndLocation = Actor->GetActorLocation();
			break;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("EndLocation: %s"), *EndLocation.ToString());
}

// Called every frame
void ATrutle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTurtle(DeltaTime);
}

void ATrutle::MoveTurtle(float DeltaTime)
{
	if (this->ActorHasTag("turtle1"))
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = EndLocation - CurrentLocation;
		Direction.Normalize();
		FVector NewLocation = CurrentLocation + Direction * TutrtleVelocity * DeltaTime;
		SetActorLocation(NewLocation);
	}
	if (this->ActorHasTag("turtle2"))
	{
		static float Time = 0;
		static bool bMove = true;

		if (bMove)
		{
			FVector CurrentLocation = GetActorLocation();
			FVector Direction = EndLocation - CurrentLocation;
			Direction.Normalize();
			FVector NewLocation = CurrentLocation + Direction * TutrtleVelocity * DeltaTime;
			SetActorLocation(NewLocation);
			Time += DeltaTime;
			if (Time >= 1)
			{
				Time = 0;
				bMove = false;
			}
		}
		else
		{
			Time += DeltaTime;
			if (Time >= 0.5)
			{
				Time = 0;
				bMove = true;
			}
		}
	}
	if (this->ActorHasTag("turtle3"))
	{
		static float Time = 0;
		static bool bMove = true;
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = EndLocation - CurrentLocation;
		Direction.Normalize();

		if (bMove)
		{
			FVector NewLocation = CurrentLocation + Direction * TutrtleVelocity * DeltaTime;
			SetActorLocation(NewLocation);
			Time += DeltaTime;
			if (Time >= 1)
			{
				Time = 0;
				bMove = false;
			}
		}
		else
		{
			FVector NewLocation = CurrentLocation - Direction * TutrtleVelocity * DeltaTime;
			SetActorLocation(NewLocation);
			Time += DeltaTime;
			if (Time >= 0.5)
			{
				Time = 0;
				bMove = true;
			}
		}
	}
}
