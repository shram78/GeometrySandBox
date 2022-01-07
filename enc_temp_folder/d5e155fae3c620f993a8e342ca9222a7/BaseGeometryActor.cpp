// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h" 

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	//printTypes();
	//printStringTypes();
	printTransform();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float time = GetWorld()->GetTimeSeconds();
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);

	SetActorLocation(CurrentLocation);
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();

	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Trannsform: %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Locations: %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotations: %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale: %s"), *Scale.ToString());
	UE_LOG(LogBaseGeometry, Error, TEXT("To Human Transform: %s"), *Transform.ToHumanReadableString());
}

//void ABaseGeometryActor::printTypes()
//{
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Weap num: %d, kills num: %i"), WeaponsNum, KillNum);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("IsDead %d"), IsDead);
//	UE_LOG(LogBaseGeometry, Warning, TEXT("HasWeapon %d"), static_cast<int>(HasWeapon));
//}

//void ABaseGeometryActor::printStringTypes()
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
