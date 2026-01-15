#include "Moving.h"

AMoving::AMoving()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MovingSpeed = 200.f;
	Reverse = false;
	Range = 500.f;
}

void AMoving::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
}

void AMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MovingSpeed))
	{
		if (Reverse)
		{
			AddActorLocalOffset(FVector(0.f, -MovingSpeed * DeltaTime, 0.f));
		}
		else
		{
			AddActorLocalOffset(FVector(0.f, MovingSpeed * DeltaTime, 0.f));
		}
		if (FVector::Dist(GetActorLocation(), StartPosition) >= Range)
		{
			Reverse = !Reverse;
		}
	}
}

