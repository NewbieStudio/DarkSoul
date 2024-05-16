// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputMappingContext* PlayerMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
	class UInputAction* LookAction;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;
};