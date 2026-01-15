#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Treasure.generated.h"

UCLASS()
class NBC_UE_P6_API ATreasure : public AActor
{
	GENERATED_BODY()
	
public:	
	ATreasure();

protected:
	virtual void BeginPlay() override;
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Comp")
	UStaticMeshComponent* StaticMeshComp;

};
