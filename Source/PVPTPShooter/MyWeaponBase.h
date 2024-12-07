// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyWeaponBase.generated.h"

UENUM(BlueprintType)
namespace EProjectileType
{

	enum EProjType
	{
		EBullet,
		ESpread,
		EExplosive
	};
}


USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Ammo)
	int32 MaxAmmo;

	UPROPERTY(EditDefaultsOnly, Category = Config)
	float ShotCooldown;

	UPROPERTY(EditDefaultsOnly, Category = Ammo)
	int32 AmmoCost;

	UPROPERTY(EditDefaultsOnly, Category = Config)
	float WeaponRange;

	UPROPERTY(EditDefaultsOnly, Category = Config)
	float WeaponSpread;
};



UCLASS()
class PVPTPSHOOTER_API AMyWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	AMyWeaponBase();

	UFUNCTION()
	void OnFire();

	UFUNCTION()
	//void OnInstantFire();

	UPROPERTY(EditDefaultsOnly, Category = Config)
	FWeaponData WeaponSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Config)
	TEnumAsByte<EProjectileType::EProjType> ProjectileType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Collision)
	UBoxComponent* CollisionComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Config)
	USkeletalMeshComponent* WeaponMesh;

protected:

	//FHitResult WeaponTrace(const FVector& TraceFrom, const FVector& TraceTo) const;

	//void ProcessInstantHit(const FHitResult& Impact, const FVector& Origin, const FVector& ShootDir, const int32 &RandomSeed, const float &ReticalSpread);

};
