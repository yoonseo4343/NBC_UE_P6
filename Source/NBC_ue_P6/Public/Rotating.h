#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotating.generated.h"

UCLASS()
class NBC_UE_P6_API ARotating : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotating();

protected:
	virtual void BeginPlay() override;
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Comp")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Custom")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	bool Reverse;
	virtual void Tick(float DeltaTime) override;
};
