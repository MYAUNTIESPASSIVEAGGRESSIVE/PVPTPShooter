// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayer1AnimInst.generated.h"

/**
 * 
 */
UCLASS()
class PVPTPSHOOTER_API UMyPlayer1AnimInst : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "Player1Anim")
	void CustomUpdateAnimation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player1Anim")
	bool bIsJumping;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player1Anim")
	bool bIsCrouched;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player1Anim")
	float MoveSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player1Anim")
	class APawn* Player;

};


