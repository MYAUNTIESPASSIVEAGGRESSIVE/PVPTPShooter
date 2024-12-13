// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	possesedPawn = Cast<AMyPlayerCharacter>(GetPawn());
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


}

void AMyPlayerController::CastMoveForward(float value)
{
	if (possesedPawn)
	{
		possesedPawn->MoveForward(value);
	}
}

void AMyPlayerController::CastMoveRight(float value)
{
	if (possesedPawn)
	{
		possesedPawn->MoveRight(value);
	}
}

void AMyPlayerController::CastShoot()
{
	if (possesedPawn)
	{
		possesedPawn->Shoot();
	}
}