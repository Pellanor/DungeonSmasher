// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "MapTile.generated.h"

UENUM(BlueprintType)
enum class TILE_TYPE : uint8
{
	TT_Floor 	UMETA(DisplayName = "Floor"),
	TT_Wall 	UMETA(DisplayName = "Wall"),
	TT_Food 	UMETA(DisplayName = "Food"),
	TT_Steel 	UMETA(DisplayName = "Steel"),
	TT_Fort 	UMETA(DisplayName = "Fort")
};

/**
 * 
 */
UCLASS(Blueprintable)
class DUNGEONSMASHER_API UMapTile : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Tile Type", ExposeOnSpawn = true))
	TILE_TYPE type;
};
