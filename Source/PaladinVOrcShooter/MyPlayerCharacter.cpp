// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPlayerAnimInstance.h"
#include "MyPlayerController.h"
#include "MyPVPGameMode.h"
#include "MyWeaponBase.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Camera Creator
	CameraHolder = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Holder"));
	CameraHolder->SetupAttachment(RootComponent);

	CameraHolder->SetRelativeLocation(FVector(0, 0, 70.0));
	CameraHolder->TargetArmLength = 300.0f;
	CameraHolder->SocketOffset = FVector(0.0, 70.0, 20.0);

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->SetupAttachment(CameraHolder);

	// Camera rotation bools
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// what parts of the camera use the control rotation
	CameraHolder->bUsePawnControlRotation = true;
	PlayerCamera->bUsePawnControlRotation = false;

	// variables for character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentPlayerHealth = MaxPlayerHealth;

	BisDead = false;

	if (WeaponClass)
	{
		FActorSpawnParameters WeaponSpawnParam;
		WeaponSpawnParam.bNoFail = true;
		WeaponSpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FTransform WeaponTransform;
		WeaponTransform.SetLocation(FVector::ZeroVector);
		WeaponTransform.SetRotation(FQuat(FRotator::ZeroRotator));

		MyWeapon = GetWorld()->SpawnActor<AMyWeaponBase>(WeaponClass, WeaponTransform, WeaponSpawnParam);

		if (MyWeapon)
		{
			MyWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName(PlayerSocketName));
		}
	}
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentPlayerHealth > MaxPlayerHealth)
	{
		CurrentPlayerHealth = MaxPlayerHealth;
	}

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Log, TEXT("player1 bound"));

	// Player World Movement
	InputComponent->BindAxis("MoveForward", this, &AMyPlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerCharacter::MoveRight);

	InputComponent->BindAxis("MoveForwardGP", this, &AMyPlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRightGP", this, &AMyPlayerCharacter::MoveRight);

	// Player Camera Movememt
	InputComponent->BindAxis("LookRight", this, &AMyPlayerCharacter::AddControllerPitchInput);
	InputComponent->BindAxis("LookUp", this, &AMyPlayerCharacter::AddControllerYawInput);

	InputComponent->BindAxis("LookRightGP", this, &AMyPlayerCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUpGP", this, &AMyPlayerCharacter::AddControllerPitchInput);

	// Player Actions
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayerCharacter::StopJumping);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayerCharacter::Shoot);
	InputComponent->BindAction("Aiming", IE_Pressed, this, &AMyPlayerCharacter::Aiming);
	InputComponent->BindAction("Aiming", IE_Released, this, &AMyPlayerCharacter::StopAiming);
	//InputComponent->BindAction("Pause", IE_Released, this, &);

	InputComponent->BindAction("JumpGP", IE_Pressed, this, &AMyPlayerCharacter::Jump);
	InputComponent->BindAction("JumpGP", IE_Released, this, &AMyPlayerCharacter::StopJumping);
	InputComponent->BindAction("ShootGP", IE_Pressed, this, &AMyPlayerCharacter::Shoot);
	InputComponent->BindAction("AimingGP", IE_Pressed, this, &AMyPlayerCharacter::Aiming);
	InputComponent->BindAction("AimingGP", IE_Released, this, &AMyPlayerCharacter::StopAiming);
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
	if(MyWeapon && MyWeapon->CurrAmmo > 0)
	{
		MyWeapon->ShootGun();
	}
}

void AMyPlayerCharacter::Aiming()
{
	CameraHolder->TargetArmLength = 50.0f;

}

void AMyPlayerCharacter::StopAiming()
{
	CameraHolder->TargetArmLength = 300.0f;


}

float AMyPlayerCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	float DamageCaused = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	DamageCaused = FMath::Min(CurrentPlayerHealth, DamageCaused);

	CurrentPlayerHealth -= DamageCaused;

	if (CurrentPlayerHealth <= 0)
	{
		BisDead = true;
	}

	UE_LOG(LogTemp, Log, TEXT("Damaged"));

	return DamageCaused;
}
