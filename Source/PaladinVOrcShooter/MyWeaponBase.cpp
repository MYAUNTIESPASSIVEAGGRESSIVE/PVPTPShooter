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

/*
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

	FHitResult GunShotHit;
	FVector StartPos = GunMesh->GetComponentLocation();
	FVector EndPos = (GunMesh->GetRightVector() * 2000) + StartPos;
	FCollisionQueryParams ColParams = FCollisionQueryParams();
	ColParams.AddIgnoredActor(this);
	ColParams.AddIgnoredActor(GetParentActor());
	bool bHasHit = GetWorld()->LineTraceSingleByChannel(GunShotHit, StartPos, EndPos, ECollisionChannel::ECC_PhysicsBody, ColParams);

	if (bHasHit)
	{
		if (auto OtherHitBox = Cast<AMyPlayerCharacter>(GunShotHit.GetActor()))
		{
			FPointDamageEvent DMGEvent(Damage, GunShotHit, GunMesh->GetRightVector(), nullptr);
			OtherHitBox->TakeDamage(Damage, DMGEvent, GetInstigatorController(), this);
			UE_LOG(LogTemp, Log, TEXT("Hit!"));
			GLog->Log(GunShotHit.GetActor()->GetName());
		}
	}

	DrawDebugLine(GetWorld(), StartPos, EndPos, FColor::Green, true, -1, 0, 1.f);
}

void AMyWeaponBase::ReloadGun()
{
	CurrAmmo = MaxAmmo;

	CurrReserveAmmo -= 15;
}
*/

