// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include <DarkSoul/SoulEnumType.h>
#include "SoulBaseCharacter.generated.h"

UCLASS()
class DARKSOUL_API ASoulBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASoulBaseCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	virtual void Attack();

	void Run();

	void StopRun();

	UPROPERTY(BlueprintReadOnly, Category = Attribute)
	bool bRunning;

	UPROPERTY(BlueprintReadWrite, Category = Attribute)
	EWeaponType WeaponType;

	UPROPERTY(BlueprintReadWrite, Category = Attribute)
	EMeleeType MeleeType;

	UPROPERTY(BlueprintReadWrite, Category = Attribute)
	EPlayerBehavior PlayerBehavior;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputMappingContext* PlayerMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* AttackAction;
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;
};