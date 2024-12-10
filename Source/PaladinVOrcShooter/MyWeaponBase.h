// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "MyWeaponBase.generated.h"

USTRUCT(BlueprintType)
struct FWeaponTable : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WeaponID;

	UPROPERTY(EditAnywhere)
	USkeletalMesh* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponMaxDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponMinDamage;
};


UCLASS()
class PALADINVORCSHOOTER_API AMyWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditAnywhere)
	UDataTable* WeaponDataTable;

	FWeaponTable* WeaponData;

public:	
	void ShootGun();

};
