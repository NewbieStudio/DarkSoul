// Fill out your copyright notice in the Description page of Project Settings.


#include "DarkSoul/Character/SoulPlayerCharacter.h"
#include "../SoulPlayerController.h"
#include <Kismet/KismetMathLibrary.h>


ASoulPlayerCharacter::ASoulPlayerCharacter()
{
	LastMeleeAttackIndex = 0;
	BattleToCommonTime = 10.0f;
}

void ASoulPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (WarState == EWarState::PREPARE && PlayerBehavior != EPlayerBehavior::ATTACK)
	{
		BattleToCommonTime -= DeltaTime;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, FString::Printf(TEXT("BattleToCommon ==> %f"), BattleToCommonTime));
		if (BattleToCommonTime <= 0)
		{
			WarState = EWarState::COMMON;
			BattleToCommonTime = 10.0f;
		}
	}
}

void ASoulPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (ASoulPlayerController* PC = Cast<ASoulPlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void ASoulPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoulBaseCharacter::Move);
		}

		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASoulBaseCharacter::Look);
		}

		if (RunAction)
		{
			EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ASoulBaseCharacter::Run);
			EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ASoulBaseCharacter::StopRun);
		}

		if (AttackAction)
		{
			EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ASoulBaseCharacter::Attack);
		}
	}
}

void ASoulPlayerCharacter::Attack()
{
	switch (WeaponType)
	{
	case EWeaponType::MELEE:
		MeleeAttack();
		break;
	case EWeaponType::SWORD:
		SwordAttck();
		break;
	}
}

void ASoulPlayerCharacter::MeleeAttack()
{
	if (CanMeleeAttack())
	{
		if (UAnimInstance* CurAnimIns = GetMesh()->GetAnimInstance())
		{
			PlayerBehavior = EPlayerBehavior::ATTACK;
			WarState = EWarState::PREPARE;
			BattleToCommonTime = 10.0f;
			int32 AttackAnimIndex = UKismetMathLibrary::RandomIntegerInRange(0, MeleeAttackAnim.Num() - 1);
			if (LastMeleeAttackIndex != AttackAnimIndex)
			{
				LastMeleeAttackIndex = AttackAnimIndex;
				CurAnimIns->Montage_Play(MeleeAttackAnim[AttackAnimIndex]);
			}
			else
			{
				if (AttackAnimIndex == 0)
				{
					int AddIndexNum = UKismetMathLibrary::RandomIntegerInRange(0, MeleeAttackAnim.Num() - 1);
					AttackAnimIndex += AddIndexNum;
					LastMeleeAttackIndex = AttackAnimIndex;
					CurAnimIns->Montage_Play(MeleeAttackAnim[AttackAnimIndex]);
				}
				else
				{
					AttackAnimIndex--;
					LastMeleeAttackIndex = AttackAnimIndex;
					CurAnimIns->Montage_Play(MeleeAttackAnim[AttackAnimIndex]);
				}
			}
		}
	}
}

void ASoulPlayerCharacter::SwordAttck()
{
}

bool ASoulPlayerCharacter::CanMeleeAttack()
{
	return PlayerBehavior == EPlayerBehavior::IDLE;
}
