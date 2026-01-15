#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moving.generated.h"

UCLASS()
class NBC_UE_P6_API AMoving : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoving();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Comp")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float MovingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	bool Reverse;
	FVector StartPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float Range;
};
