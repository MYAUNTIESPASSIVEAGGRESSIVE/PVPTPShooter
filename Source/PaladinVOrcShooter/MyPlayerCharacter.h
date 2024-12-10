// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
	float MovementSpeed = 600.0f;

	// Weapon Classes
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMyWeaponBase> WeaponClass;

	class AMyWeaponBase* MyWeapon;


	// Functions
	void Shoot();

	void MoveForward(float value);

	void MoveRight(float value);

};
