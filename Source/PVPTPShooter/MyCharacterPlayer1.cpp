// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterPlayer1.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyCharacterPlayer1::AMyCharacterPlayer1()
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

}

// Called when the game starts or when spawned
void AMyCharacterPlayer1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterPlayer1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterPlayer1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!UseGamePad) 
	{
		// Player World Movement
		PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacterPlayer1::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacterPlayer1::MoveRight);

		// Player Camera Movememt
		PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerYawInput);

		// Player One Actions
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacterPlayer1::Jump);
	}
	else
	{

	}
}

void AMyCharacterPlayer1::MoveForward(float axis) 
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, axis);
}

void AMyCharacterPlayer1::MoveRight(float axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, axis);
}

void AMyCharacterPlayer1::Jump() 
{

}

