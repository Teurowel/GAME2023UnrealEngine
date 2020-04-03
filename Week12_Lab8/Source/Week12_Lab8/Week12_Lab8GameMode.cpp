// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Week12_Lab8GameMode.h"
#include "Week12_Lab8HUD.h"
#include "Week12_Lab8Character.h"
#include "UObject/ConstructorHelpers.h"

AWeek12_Lab8GameMode::AWeek12_Lab8GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWeek12_Lab8HUD::StaticClass();
}
