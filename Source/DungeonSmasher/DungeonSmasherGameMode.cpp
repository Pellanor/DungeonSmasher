// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "DungeonSmasher.h"
#include "DungeonSmasherGameMode.h"
#include "DungeonSmasherPlayerController.h"
#include "DungeonSmasherCharacter.h"

ADungeonSmasherGameMode::ADungeonSmasherGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADungeonSmasherPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}