// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer1AnimInst.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyPlayer1AnimInst::NativeInitializeAnimation()
{
	if (Player == nullptr)
	{
		Player = TryGetPawnOwner();
	}
}

void UMyPlayer1AnimInst::CustomUpdateAnimation()
{
	if (Player == nullptr)
	{
		Player = TryGetPawnOwner();
	}
	if (Player)
	{
		FVector Speed = Player->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0);
		MoveSpeed = LateralSpeed.Size();

		bIsJumping = Player->GetMovementComponent()->IsFalling();
	}
}

