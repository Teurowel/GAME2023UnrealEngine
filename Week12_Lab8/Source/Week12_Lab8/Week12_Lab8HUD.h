// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Week12_Lab8HUD.generated.h"

UCLASS()
class AWeek12_Lab8HUD : public AHUD
{
	GENERATED_BODY()

public:
	AWeek12_Lab8HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

