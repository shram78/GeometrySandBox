// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
//#include "Engine/Engine.h" 

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	FString Name = "Aleks Shram";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	int WeaponsNum = 3;
	float Health = 34.3454543f;
	bool IsDead = false;

	FString WeaponsNumStr = "Weapons num: " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health: " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "IsDead: " + FString(IsDead ? "True Player" : "False Player");

	FString Stats = FString::Printf(TEXT("\n == All stats == \n %s,\n %s,\n %s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stats);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stats, true, FVector2D(1.5f, 1.5f));


}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::printTypes()
{
	int WeaponsNum = 3;
	int KillNum = 7;
	float Health = 34.3454543f;
	bool IsDead = false;
	bool HasWeapon = true;

	UE_LOG(LogTemp, Display, TEXT("Weap num: %d, kills num: %i"), WeaponsNum, KillNum);
	UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Health: %.2f"), Health);
	UE_LOG(LogTemp, Display, TEXT("IsDead %d"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("HasWeapon %d"), static_cast<int>(HasWeapon));
}