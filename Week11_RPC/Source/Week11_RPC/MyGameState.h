// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class WEEK11_RPC_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public :
	UPROPERTY(BlueprintReadOnly, Category = "Message", ReplicatedUsing = OnRep_ArrayOfMsg)
	TArray<FString> ArrayOfMsg;

	//NOTE: The event is not triggered on the server. We have to manually call on server
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRep_ArrayOfMsg();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
