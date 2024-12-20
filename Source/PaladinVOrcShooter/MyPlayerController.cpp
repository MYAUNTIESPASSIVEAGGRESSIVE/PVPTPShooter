// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	possesedPawn = Cast<AMyPlayerCharacter>(GetPawn());

	if (HUDOverlayAsset)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
		HUDOverlay->AddToViewport();
		HUDOverlay->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto gameMode = Cast<AMyPVPGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (gameMode->PlayerOne == Cast<AMyPlayerCharacter>(GetPawn()))
		{
			UE_LOG(LogTemp, Log, TEXT("player1 bound"));

			// Player One World Movement
			InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::CastMoveForward);
			InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::CastMoveRight);

			// Player One Camera Movememt
			InputComponent->BindAxis("LookRight", this, &AMyPlayerController::CastLookRight);
			InputComponent->BindAxis("LookUp", this, &AMyPlayerController::CastLookUp);

			// Player One Actions
			InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerController::CastJump);
			InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayerController::CastStopJumping);
			InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayerController::CastShoot);
			InputComponent->BindAction("Aiming", IE_Pressed, this, &AMyPlayerController::CastAiming);
			InputComponent->BindAction("Aiming", IE_Released, this, &AMyPlayerController::CastStopAiming);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("player2 bound"));
			// Player Two World Movement
			InputComponent->BindAxis("MoveForwardGP", this, &AMyPlayerController::CastMoveForward);
			InputComponent->BindAxis("MoveRightGP", this, &AMyPlayerController::CastMoveRight);

			// Player Two Camera Movememt
			InputComponent->BindAxis("LookRightGP", this, &AMyPlayerController::CastLookRight);
			InputComponent->BindAxis("LookUpGP", this, &AMyPlayerController::CastLookUp);

			// Player Two Actions
			InputComponent->BindAction("JumpGP", IE_Pressed, this, &AMyPlayerController::CastJump);
			InputComponent->BindAction("JumpGP", IE_Released, this, &AMyPlayerController::CastStopJumping);
			InputComponent->BindAction("ShootGP", IE_Pressed, this, &AMyPlayerController::CastShoot);
			InputComponent->BindAction("AimingGP", IE_Pressed, this, &AMyPlayerController::CastAiming);
			InputComponent->BindAction("AimingGP", IE_Released, this, &AMyPlayerController::CastStopAiming);
			InputComponent->BindAction("AimingGP", IE_Released, this, &AMyPlayerController::CastStopAiming);
		}
	}
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