// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkSoul/Character/SoulBaseCharacter.h"
#include "SoulPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DARKSOUL_API ASoulPlayerCharacter : public ASoulBaseCharacter
{
	GENERATED_BODY()

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
