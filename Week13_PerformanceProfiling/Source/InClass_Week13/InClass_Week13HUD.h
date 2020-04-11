// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InClass_Week13HUD.generated.h"

UCLASS()
class AInClass_Week13HUD : public AHUD
{
	GENERATED_BODY()

public:
	AInClass_Week13HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

