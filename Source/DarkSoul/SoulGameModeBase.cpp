// Copyright Epic Games, Inc. All Rights Reserved.


#include "SoulGameModeBase.h"
#include "SoulPlayerController.h"
#include "Character/SoulBaseCharacter.h"

ASoulGameModeBase::ASoulGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ASoulBaseCharacter> BPPlayerClass(TEXT("/Script/Engine.Blueprint'/Game/Game/BP/BP_Player'"));
	if (BPPlayerClass.Class)
	{
		DefaultPawnClass = BPPlayerClass.Class;
	}

	PlayerControllerClass = ASoulPlayerController::StaticClass();
}
