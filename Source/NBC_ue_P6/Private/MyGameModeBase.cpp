#include "MyGameModeBase.h"
#include "Engine/World.h"
#include "Treasure.h"

void AMyGameModeBase::BeginPlay()
{
    SpawnRandom();
}

void AMyGameModeBase::SpawnRandom()
{
    if (!TreasureClass)
        return;

    UWorld* World = GetWorld();

    if (!World)
        return;

    int32 idx = FMath::RandRange(0, SpawnLocations.Num() - 1);

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    if (!World->SpawnActor<ATreasure>(
        TreasureClass,
        SpawnLocations[idx],
        FRotator::ZeroRotator,
        Params
    ))
    {
        UE_LOG(LogTemp, Warning, TEXT("Treasure Spawn Failed."));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Treasure Spawn."));
    }

}