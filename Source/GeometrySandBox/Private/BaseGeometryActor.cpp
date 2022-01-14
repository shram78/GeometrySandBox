#include "BaseGeometryActor.h"
#include "Engine/Engine.h" 

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)


ABaseGeometryActor::ABaseGeometryActor()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	//PrintTypes();
	//PrintStringTypes();
	//PrintTransform();
}

void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMovement();
}

void ABaseGeometryActor::HandleMovement()
{
	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
	{
		FVector CurrentLocation = GetActorLocation();
		float Time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * Time);

		SetActorLocation(CurrentLocation);
	}
	break;

	case EMovementType::Static: break;
	default: break;
	}
}

//void ABaseGeometryActor::PrintTransform()
//{
//	FTransform Transform = GetActorTransform();
//
//	FVector Location = Transform.GetLocation();
//	FRotator Rotation = Transform.Rotator();
//	FVector Scale = Transform.GetScale3D();
//
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Trannsform: %s"), *Transform.ToString());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Locations: %s"), *Location.ToString());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotations: %s"), *Rotation.ToString());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale: %s"), *Scale.ToString());
//	UE_LOG(LogBaseGeometry, Error, TEXT("To Human Transform: %s"), *Transform.ToHumanReadableString());
//}

//void ABaseGeometryActor::PrintTypes()
//{
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Weap num: %d, kills num: %i"), WeaponsNum, KillNum);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("IsDead %d"), IsDead);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("HasWeapon %d"), static_cast<int>(HasWeapon));
//}

//void ABaseGeometryActor::PrintStringTypes()
//{
//	FString Name = "Aleks Shram";
//	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);
//
//	FString WeaponsNumStr = "Weapons num: " + FString::FromInt(WeaponsNum);
//	FString HealthStr = "Health: " + FString::SanitizeFloat(Health);
//	FString IsDeadStr = "IsDead: " + FString(IsDead ? "True Player" : "False Player");
//
//	FString Stats = FString::Printf(TEXT("\n == All stats == \n %s,\n %s,\n %s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
//	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stats);
//
//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stats, true, FVector2D(1.5f, 1.5f));
//}
