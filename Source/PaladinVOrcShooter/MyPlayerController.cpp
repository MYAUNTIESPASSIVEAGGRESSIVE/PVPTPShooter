// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//AMyPVPGameMode* GameMode = Cast<AMyPVPGameMode>(UGameplayStatics::GetGameMode(this));
}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();



}


// casts movement to the respective areas when input from the player controller
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


void AMyPlayerController::CastLookUp(float value)
{
	if (possesedPawn)
	{
		possesedPawn->AddControllerYawInput(value);
	}
}

void AMyPlayerController::CastLookRight(float value)
{
	if (possesedPawn)
	{
		possesedPawn->AddControllerPitchInput(value);
	}
}

void AMyPlayerController::CastJump()
{
	if (possesedPawn)
	{
		possesedPawn->Jump();
	}
}

void AMyPlayerController::CastStopJumping()
{
	if (possesedPawn)
	{
		possesedPawn->StopJumping();
	}
}


void AMyPlayerController::CastShoot()
{
	if (possesedPawn)
	{
		possesedPawn->Shoot();
	}
}

void AMyPlayerController::CastAiming()
{
	if (possesedPawn)
	{
		possesedPawn->Aiming();
	}
}

void AMyPlayerController::CastStopAiming()
{
	if (possesedPawn)
	{
		possesedPawn->StopAiming();
	}
}
