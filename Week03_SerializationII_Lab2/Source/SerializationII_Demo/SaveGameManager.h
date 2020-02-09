// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SaveGame.h"

#include "ObjectAndNameAsStringProxyArchive.h"
#include "SaveGameManager.generated.h"

UINTERFACE(MinimalAPI)
class USavableObject : public UInterface
{
	GENERATED_BODY()
};

class ISavableObject
{
	GENERATED_BODY()

public:

	//Do something after every game object is safely loaded
	UFUNCTION(BlueprintNativeEvent)
	bool OnAllObjectsLoaded();
	virtual bool OnAllObjectsLoaded_Implementation() { return true; }

	//Don't save this object - sometimes useful
	UFUNCTION(BlueprintNativeEvent)
	bool SkipSave();
	virtual bool SkipSave_Implementation() { return false; }

	UFUNCTION(BlueprintNativeEvent)
	bool OnAfterLoaded();
	virtual bool OnAfterLoaded_Implementation() { return true;  }
};

UCLASS(ClassGroup = (SaveGame), BlueprintType, Blueprintable, editinlinenew)
class UDemoSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	//Actors to save
	UPROPERTY(SaveGame, VisibleInstanceOnly, Category = Data)
	TArray<AActor*> WorldActors;

	//Components to save
	UPROPERTY(SaveGame, VisibleInstanceOnly, Category = Data)
	TArray<UActorComponent*> WorldActorComponents;
};

struct FDemoSaveGameArchive : public FObjectAndNameAsStringProxyArchive
{
	class USaveGameManager* SaveGameManager;
	TArray<AActor*> LoadedActors;

	FDemoSaveGameArchive(FArchive& InInnerArchive, bool bInLoadIfFindFails)
		: FObjectAndNameAsStringProxyArchive(InInnerArchive, bInLoadIfFindFails)
	{
		ArIsSaveGame = true;
		ArNoDelta = true;//Force serialization of property, even when set to default
	}

	FArchive& operator<<(class UObject*& Obj);

	//If we don't override the behaviour for this object type, use the base archive class' operator <<
	FORCEINLINE FArchive& BaseArchive(class UObject*& Obj)
	{
		FObjectAndNameAsStringProxyArchive::operator <<(Obj);
		return *this;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SERIALIZATIONII_DEMO_API USaveGameManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	USaveGameManager();

public:	

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Save(const FString& GameSlotName);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Load(const FString& GameSlotName);

private:
	void SaveGameToSlot(UDemoSaveGame* SaveGameObj, FString SlotName, int32 UserIndex);
	USaveGame* LoadGameFromSlot(const FString& SlotName, const int32 UserIndex);
};
