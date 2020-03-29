// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"
#include "UnrealNetwork.h"

void AMyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyGameState, ArrayOfMsg);
}