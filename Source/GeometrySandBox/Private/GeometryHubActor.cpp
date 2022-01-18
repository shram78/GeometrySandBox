
#include "GeometryHubActor.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogGeometryHub, All, All)

AGeometryHubActor::AGeometryHubActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();

	//DoActorSpawn1();
	//DoActorSpawn3();
	DoActorSpawn3();
}

void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeometryHubActor::DoActorSpawn1()
{
	UWorld* World = GetWorld();

	if (World)
	{
		for (int32 i = 0; i < 10; i++)
		{
			const FTransform GeometryTarnsform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 300.0f));
			ABaseGeometryActor* Geometry = World->SpawnActor<ABaseGeometryActor>(GeometryClass, GeometryTarnsform);

			if (Geometry)
			{
				FGeometryData Data;
				Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
				Geometry->SetGeometryData(Data);
			}
		}
	}
}

void AGeometryHubActor::DoActorSpawn2()
{
	UWorld* World = GetWorld();

	//спаун актора с отложенным вызовом бегин плай. Можно задать параметрры актора до его спауна
	for (int32 i = 0; i < 10; i++)
	{
		const FTransform GeometryTarnsform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 700.0f));
		ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryClass, GeometryTarnsform);

		if (Geometry)
		{
			FGeometryData Data;
			Data.Color = FLinearColor::MakeRandomColor();
			Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
			Geometry->SetGeometryData(Data);
			Geometry->FinishSpawning(GeometryTarnsform);
		}
	}
}

void AGeometryHubActor::DoActorSpawn3()
{
	UWorld* World = GetWorld();

	for (const FGeometryPayload Payload : GeometryPayloads)
	{
		ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(Payload.GeometryClass, Payload.InitialTransform);
		if (Geometry)
		{
			Geometry->SetGeometryData(Payload.Data);
			Geometry->OnColorChanged.AddDynamic(this, &AGeometryHubActor::OnColorChange);
			Geometry->OnTimerFinished.AddUObject(this, &AGeometryHubActor::OnTimerFinished);

			Geometry->FinishSpawning(Payload.InitialTransform);
		}
	}
}

void AGeometryHubActor::OnColorChange(const FLinearColor& Color, const FString& Name)
{
	UE_LOG(LogGeometryHub, Warning, TEXT("Actor name: %s Color %s"), *Name, *Color.ToString());
}

void AGeometryHubActor::OnTimerFinished(AActor* Actor)
{
	if (!Actor) return;
	UE_LOG(LogGeometryHub, Error, TEXT("Timer finished: %s"), *Actor->GetName());

	ABaseGeometryActor* Geometry = Cast<ABaseGeometryActor>(Actor);
	if (!Geometry) return;

	UE_LOG(LogGeometryHub, Display, TEXT("Cast is success %f"), Geometry->GetGeometryData().Amplitude);

	Geometry->Destroy();
	//Geometry->SetLifeSpan(2.0f);
}