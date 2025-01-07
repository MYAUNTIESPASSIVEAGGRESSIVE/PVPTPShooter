// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyPlayerCharacter.h"
#include "Engine/DamageEvents.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyWeaponBase::AMyWeaponBase()
{
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>("GunMeshComponent");
	RootComponent = GunMesh;

	CurrAmmo = MaxAmmo;

	CurrReserveAmmo = MaxReserveAmmo;
}

// Called when the game starts or when spawned
void AMyWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AMyWeaponBase::ShootGun()
{
	if (CurrAmmo > 0)
	{
		CurrAmmo -= 1;
	}
	
	if(CurrAmmo <= 0 && CurrReserveAmmo > 0)
	{
		ReloadGun();
	}
	else
	{

	}

	FHitResult ShotHit;
	FVector StartPos = GunMesh->GetComponentLocation();
	FVector EndPos = (GunMesh->GetRightVector() * 200) + StartPos;
	FCollisionQueryParams ColParams = FCollisionQueryParams();
	ColParams.AddIgnoredActor(this);
	bool bHasHit = GetWorld()->LineTraceSingleByChannel(ShotHit, StartPos, EndPos, ECollisionChannel::ECC_PhysicsBody, ColParams);

	if (bHasHit)
	{
		if (auto PlayerOther = Cast<AMyPlayerCharacter>(ShotHit.GetActor()))
		{
			FPointDamageEvent DMGEvent(20, ShotHit, GunMesh->GetRightVector(), nullptr);
			PlayerOther->TakeDamage(20, DMGEvent, GetInstigatorController(), this);
			UE_LOG(LogTemp, Log, TEXT("HIT"));
		}
	}

	DrawDebugLine(GetWorld(), StartPos, EndPos, FColor::Green, true, -1, 0, 1.f);
}

void AMyWeaponBase::ReloadGun()
{
	CurrAmmo = MaxAmmo;

	CurrReserveAmmo -= 15;
}

