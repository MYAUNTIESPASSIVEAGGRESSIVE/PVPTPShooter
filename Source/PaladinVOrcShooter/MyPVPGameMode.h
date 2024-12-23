
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerCharacter.h"
#include "MyPVPGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PALADINVORCSHOOTER_API AMyPVPGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AMyPVPGameMode();
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players")
	AMyPlayerCharacter* PlayerOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players")
	AMyPlayerCharacter* PlayerTwo;
};
