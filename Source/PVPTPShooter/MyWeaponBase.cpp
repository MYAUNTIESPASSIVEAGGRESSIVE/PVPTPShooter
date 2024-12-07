// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBase.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyWeaponBase::AMyWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Comp"));

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);

}

void AMyWeaponBase::OnFire() 
{
	if (ProjectileType == EProjectileType::EBullet) 
	{
		OnInstantFire();
	}

	if (ProjectileType == EProjectileType::ESpread)
	{
		for (int32 i = 0; i <= WeaponSystem.WeaponSpread; i++)
		{
			OnInstantFire();
		}
	}

	if (ProjectileType == EProjectileType::EExplosive)
	{
		OnInstantFire();
	}
}

/*
// this function deals with player firing, it calcuslates the trace and then starts the impact function afterwards UNCOMMENT WHEN CARRYING ON DUMBASS
void AMyWeaponBase::OnInstantFire()
{
	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);

	// details wepaon spread, cone of spread;
	const float CurrentSpread = WeaponSystem.WeaponSpread;
	const float SpreadCone = FMath::DegreesToRadians(WeaponSystem.WeaponSpread * 0.05f);

	// Works out the vectors for the cast to start/end and the direction the player is aiming
	const FVector AimDir = WeaponMesh->GetSocketRotation("MF").Vector();
	const FVector TraceStart = WeaponMesh->GetSocketLocation("MF");
	const FVector ShootDir = WeaponRandomStream.VRandCone(AimDir, SpreadCone, SpreadCone);
	const FVector TraceEnd = TraceStart + ShootDir * WeaponSystem.WeaponRange;

	//Hit result
	//const FHitResult OnHit = WeaponTrace(TraceStart, TraceEnd);

	//ProcessInstantHit(OnHit, TraceStart, ShootDir, RandomSeed, CurrentSpread);

}

FHitResult AMyWeaponBase::WeaponTrace(const FVector &TraceFrom, const FVector &TraceTo) const
{
	//www.youtube.com/watch?v=ubVpYz_x_Ig&t=424s - carry on from 32:38
}

void AMyWeaponBase::ProcessInstantHit(const FHitResult& Impact, const FVector& Origin,
	const FVector& ShootDir, const int32& RandomSeed, const float& ReticalSpread)
{

}

*/

