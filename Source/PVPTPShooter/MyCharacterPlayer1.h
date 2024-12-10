// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterPlayer1.generated.h"

UCLASS()
class PVPTPSHOOTER_API AMyCharacterPlayer1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterPlayer1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TPCamera)
	class USpringArmComponent* CameraHolder;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TPCamera)
	class UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Type")
	bool bUseGamePad = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
	float MovementSpeed = 600.0f;

	void Shoot();

	void MoveForward(float value);

	void MoveRight(float value);

};
