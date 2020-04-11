// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "InClass_Week13GameMode.h"
#include "InClass_Week13HUD.h"
#include "InClass_Week13Character.h"
#include "UObject/ConstructorHelpers.h"

AInClass_Week13GameMode::AInClass_Week13GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AInClass_Week13HUD::StaticClass();
}
