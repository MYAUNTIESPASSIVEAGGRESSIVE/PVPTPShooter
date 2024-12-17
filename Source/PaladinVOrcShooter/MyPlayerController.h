// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerCharacter.h"
#include "MyPVPGameMode.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PALADINVORCSHOOTER_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	AMyPlayerCharacter* possesedPawn;

	UFUNCTION(BlueprintCallable)
	void CastShoot();

	UFUNCTION(BlueprintCallable)
	void CastJump();

	UFUNCTION(BlueprintCallable)
	void CastStopJumping();

	UFUNCTION(BlueprintCallable)
	void CastAiming();

	UFUNCTION(BlueprintCallable)
	void CastStopAiming();

	UFUNCTION(BlueprintCallable)
	void CastMoveRight(float value);

	UFUNCTION(BlueprintCallable)
	void CastMoveForward(float value);

	UFUNCTION(BlueprintCallable)
	void CastLookRight(float value);

	UFUNCTION(BlueprintCallable)
	void CastLookUp(float value);

};
