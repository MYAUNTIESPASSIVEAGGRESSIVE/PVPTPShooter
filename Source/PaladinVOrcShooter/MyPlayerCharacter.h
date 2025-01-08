// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayerWidget.h"
#include "MyWeaponBase.h"
#include "MyPlayerCharacter.generated.h"

UCLASS()
class PALADINVORCSHOOTER_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	// Camera Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TPCamera)
	class USpringArmComponent* CameraHolder;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TPCamera)
	class UCameraComponent* PlayerCamera;


	// Gamepad Checker
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Type")
	bool bUseGamePad = false;

	// Player Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
	float MovementSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Variables")
	float CurrentPlayerHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Variables")
	float MaxPlayerHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Variables")
	bool BisDead = false;

	// Weapon Classes
	UPROPERTY(EditAnywhere, Category = "Weapons Class")
	TSubclassOf <AMyWeaponBase > WeaponClass;
	AMyWeaponBase* MyWeapon;

	UPROPERTY(EditAnywhere, Category = "Socket Name")
	FString PlayerSocketName;

	FTimerHandle RespawnTimerHandle;

	// Functions
	void Shoot();

	void Aiming();

	void StopAiming();

	void MoveForward(float value);

	void MoveRight(float value);
};
