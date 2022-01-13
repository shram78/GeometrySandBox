// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Move")
		float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Move")
		float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Move")
		float RotationSpeed = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		int32 WeaponsNum = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Stat")
		int32 KillNum = 7;

	UPROPERTY(EditInstanceOnly, Category = "Health")
		float Health = 34.3454543f;

	UPROPERTY(EditAnywhere, Category = "Health")
		bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
		bool HasWeapon = true;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//void printTypes();
	//void printStringTypes();
	//void printTransform();
	FVector InitialLocation;
	//Debag.log
};
