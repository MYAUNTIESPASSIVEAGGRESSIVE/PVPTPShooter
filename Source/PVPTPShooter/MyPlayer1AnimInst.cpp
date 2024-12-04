// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer1AnimInst.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyPlayer1AnimInst::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
}

void UMyPlayer1AnimInst::CustomUpdateAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0);
		MoveSpeed = LateralSpeed.Size();

		bIsJumping = Pawn->GetMovementComponent()->IsFalling();
	}
}

