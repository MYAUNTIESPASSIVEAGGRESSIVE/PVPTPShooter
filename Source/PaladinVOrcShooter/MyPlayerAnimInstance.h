// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PALADINVORCSHOOTER_API UMyPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "PlayerAnim")
	void UpdatePlrAnimation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	bool bIsInAir;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	bool bIsCrouching;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	float PlayerMoveSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	float PlayerForwardSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	float PlayerRightSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerAnim")
	class APawn* PlayerPawn;


};
