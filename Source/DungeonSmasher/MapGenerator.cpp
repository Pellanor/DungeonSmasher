// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "MapGenerator.h"


// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapGenerator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMapGenerator::Init()
{
	this->Tiles.resize(this->Width, std::vector<UMapTile*>(this->Height, new UMapTile()));
}

