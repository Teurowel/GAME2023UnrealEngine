// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Week11_RPCGameMode.h"
#include "Week11_RPCCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyGameState.h"

AWeek11_RPCGameMode::AWeek11_RPCGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AGameStateBase> GameStateBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_MyGameState"));
	if (GameStateBPClass.Class != NULL)
	{
		GameStateClass = GameStateBPClass.Class;
	}
}