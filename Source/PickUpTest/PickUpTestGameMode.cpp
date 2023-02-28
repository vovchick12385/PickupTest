// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickUpTestGameMode.h"
#include "PickUpTestHUD.h"
#include "PickUpTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

APickUpTestGameMode::APickUpTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APickUpTestHUD::StaticClass();
}
