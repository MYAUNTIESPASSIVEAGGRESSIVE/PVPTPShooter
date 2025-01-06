// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyPlayerCharacter.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyWeaponBase::AMyWeaponBase()
{
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>("GunMeshComponent");
	RootComponent = GunMesh;
}

// Called when the game starts or when spawned
void AMyWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (WeaponDataTable)
	{
		static const FString PString = FString("Pistol");
		WeaponData = WeaponDataTable->FindRow<FWeaponTable>(FName("Weapon_Pistol"),PString, true);

		if (WeaponData)
		{
			GunMesh->SetSkeletalMesh(WeaponData->WeaponMesh);
		}
	}
}

void AMyWeaponBase::ShootGun()
{
	if (WeaponData)
	{
		TArray<FHitResult> ShotHit;
		FVector StartPos = GunMesh->GetComponentLocation();
		FVector EndPos = (GunMesh->GetRightVector() * WeaponData->WeaponRange) + StartPos;
		FCollisionQueryParams ColParams = FCollisionQueryParams();
		ColParams.AddIgnoredActor(this);
		bool bHasHit = GetWorld()->LineTraceMultiByChannel(OUT ShotHit, StartPos, EndPos, ECollisionChannel::ECC_PhysicsBody, ColParams);

		/*
				if (bHasHit)
		{
			for (FHitResult& Result : ShotHit)
			{
				if (AActor* OtherPlayer = Result.GetActor())
				{
					AMyPlayerCharacter* PlayerHit = OtherPlayer->GetComponentByClass<AMyPlayerCharacter>();

					//PlayerHit->TakeDamage(WeaponData->WeaponMaxDamage);

					UE_LOG(LogTemp, Log, TEXT("PlayerHit!"));
				}
			}
		}
		*/

		DrawDebugLine(GetWorld(), StartPos, EndPos, FColor::Green, true, -1, 0, 1.f);
	}
}

