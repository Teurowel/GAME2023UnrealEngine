// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Week10_ReplicationGameMode.h"
#include "Week10_ReplicationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeek10_ReplicationGameMode::AWeek10_ReplicationGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
