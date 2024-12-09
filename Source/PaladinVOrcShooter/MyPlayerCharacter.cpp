// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Camera Creator
	CameraHolder = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Holder"));
	CameraHolder->SetupAttachment(RootComponent);

	CameraHolder->TargetArmLength = 300.0f;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->SetupAttachment(CameraHolder);

	// Camera rotation bools
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// what parts of the camera use the control rotation
	CameraHolder->bUsePawnControlRotation = true;
	PlayerCamera->bUsePawnControlRotation = false;

	// variables for character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	if (!bUseGamePad)
	{
		// Player One World Movement
		PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayerCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayerCharacter::MoveRight);

		// Player One Camera Movememt
		PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerYawInput);

		// Player One Actions
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
		PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayerCharacter::Shoot);
	}
	/*
	else
	{
		// Player Two World Movement
		PlayerInputComponent->BindAxis("MoveForwardGP", this, &AMyPlayerCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRightGP", this, &AMyPlayerCharacter::MoveRight);

		// Player Two Camera Movememt
		PlayerInputComponent->BindAxis("LookRightGP", this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("LookUpGP", this, &APawn::AddControllerYawInput);

		// Player Two Actions
		PlayerInputComponent->BindAction("JumpGP", IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("JumpGP", IE_Released, this, &ACharacter::StopJumping);
		PlayerInputComponent->BindAction("ShootGP", IE_Pressed, this, &AMyPlayerCharacter::Shoot);
	}
	*/

}

void AMyPlayerCharacter::MoveForward(float axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, axis);
}

void AMyPlayerCharacter::MoveRight(float axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, axis);
}

void AMyPlayerCharacter::Shoot()
{

}

