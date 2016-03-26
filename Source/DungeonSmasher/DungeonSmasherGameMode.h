// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "MapGenerator.h"
#include "DungeonSmasherGameMode.generated.h"

UCLASS(minimalapi)
class ADungeonSmasherGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ADungeonSmasherGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	AMapGenerator* Map;
};



