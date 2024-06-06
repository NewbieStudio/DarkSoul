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
	ASoulPlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Attack() override;

	void MeleeAttack();

	void SwordAttck();

	bool CanMeleeAttack();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AnimMontage, meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> MeleeAttackAnim;

	int32 LastMeleeAttackIndex;

	float BattleToCommonTime;
};
