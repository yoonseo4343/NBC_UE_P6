#include "Rotating.h"

ARotating::ARotating()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.f;
	Reverse = false;

}

void ARotating::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.0f, FMath::RandRange(0.0f, 180.0f), 0.0f));
	if (FMath::RandRange(0, 1)) 
	{
		Reverse = true;
	}
	else
	{
		Reverse = false;
	}
	RotationSpeed = FMath::RandRange(80.f, 100.f);
}

void ARotating::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		if(Reverse)
		{
			AddActorLocalRotation(FRotator(0.f, -RotationSpeed * DeltaTime, 0.f));
		}
		else
		{
			AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));
		}
	}
}

