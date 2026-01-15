#include "Treasure.h"

ATreasure::ATreasure()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ATreasure::BeginPlay()
{
	Super::BeginPlay();
	
}

