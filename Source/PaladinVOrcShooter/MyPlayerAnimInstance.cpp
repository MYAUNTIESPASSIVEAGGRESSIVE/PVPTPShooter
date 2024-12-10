// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyPlayerAnimInstance::NativeInitializeAnimation()
{
	if (PlayerPawn == nullptr)
	{
		PlayerPawn = TryGetPawnOwner();
	}
}

void UMyPlayerAnimInstance::UpdatePlrAnimation()
{
	if (PlayerPawn == nullptr)
	{
		PlayerPawn = TryGetPawnOwner();
	}
	if (PlayerPawn)
	{
		FVector Speed = PlayerPawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0);
		PlayerMoveSpeed = LateralSpeed.Size();

		bIsInAir = PlayerPawn->GetMovementComponent()->IsFalling();
	}
}

