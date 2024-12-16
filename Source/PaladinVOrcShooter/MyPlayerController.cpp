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

	if (auto gameMode = Cast<AMyPVPGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (gameMode->PlayerOne == Cast<AMyPlayerCharacter>(GetPawn()))
		{
			// Player One World Movement
			InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::CastMoveForward);
			InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::CastMoveRight);

			/*
						// Player One Camera Movememt
			InputComponent->BindAxis("LookRight", this, &APawn::AddControllerPitchInput);
			InputComponent->BindAxis("LookUp", this, &APawn::AddControllerYawInput);

			// Player One Actions
			InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
			InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
			InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayerCharacter::Shoot);
			InputComponent->BindAction("Aiming", IE_Pressed, this, &AMyPlayerCharacter::Aiming);
			InputComponent->BindAction("Aiming", IE_Released, this, &AMyPlayerCharacter::StopAiming);
			*/
		}
		else
		{
			//null
		}
	}
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