#pragma once

#include "CoreMinimal.h"
#include "SoulEnumType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	NONE,
	MELEE,
	SWORD,
};

UENUM(BlueprintType)
enum class EWarState : uint8
{
	NONE,
	COMMON,
	PREPARE,
};

UENUM(BlueprintType)
enum class EPlayerBehavior : uint8
{
	NONE,
	IDLE,
	ATTACK,
	ROLLING,
	SLIDE,
	DEFENSE,
	INJURY,
};