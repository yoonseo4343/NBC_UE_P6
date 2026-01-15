#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

class ATreasure;

UCLASS()
class NBC_UE_P6_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Spawn")
	TSubclassOf<ATreasure> TreasureClass;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<FVector> SpawnLocations;

	void SpawnRandom();
};
