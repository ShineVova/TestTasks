// Copyright Epic Games, Inc. All Rights Reserved.

#include "Task2GameMode.h"
#include "Task2HUD.h"
#include "Task2Character.h"
#include "UObject/ConstructorHelpers.h"

ATask2GameMode::ATask2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATask2HUD::StaticClass();
}
