// Copyright 2015 Jason Campbell

#pragma once

#include "GameFramework/Actor.h"
#include "Map/MapTile.h"
#include <vector>
#include "MapGenerator.generated.h"

UCLASS()
class DUNGEONSMASHER_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dimensions", Meta = (DisplayName = "Width", ExposeOnSpawn = true))
	int32 Width = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dimensions", Meta = (DisplayName = "Height", ExposeOnSpawn = true))
	int32 Height = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dimensions", Meta = (DisplayName = "Tile Size", ExposeOnSpawn = true))
	int32 TileSize = 400;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Seed", ExposeOnSpawn = true))
	int32 Seed = 42;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cellular Automaton", Meta = (DisplayName = "Initial Density", ExposeOnSpawn = true))
	int32 InitalDensity = 40;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cellular Automaton", Meta = (DisplayName = "Iterations", ExposeOnSpawn = true))
	int32 AutomatonIterations = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cellular Automaton", Meta = (DisplayName = "Wall Threshold", ExposeOnSpawn = true))
	int32 AutomatonWallThreshold = 4;

	std::vector<std::vector<UMapTile*>> Tiles;

	UFUNCTION(BlueprintCallable, Category="Functions")
	void Init();


};
