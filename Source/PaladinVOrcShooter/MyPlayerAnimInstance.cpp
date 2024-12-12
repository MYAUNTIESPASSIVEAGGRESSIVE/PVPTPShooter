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
		FVector Forward = PlayerPawn->GetActorForwardVector();
		FVector Right = PlayerPawn->GetActorRightVector();

		PlayerForwardSpeed = FVector::DotProduct(Speed, Forward);
		PlayerRightSpeed = FVector::DotProduct(Speed, Right);

		bIsInAir = PlayerPawn->GetMovementComponent()->IsFalling();

		
	}
}

