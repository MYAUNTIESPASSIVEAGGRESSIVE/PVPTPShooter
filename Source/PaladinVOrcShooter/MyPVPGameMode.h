
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Statistics")
	int32 PlayerOneKills = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Statistics")
	int32 PlayerTwoKills = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Statistics")
	int32 PlayerOneDeaths = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Statistics")
	int32 PlayerTwoDeaths = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Statistics")
	int32 KillsToWin = 8;

};
