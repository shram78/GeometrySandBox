#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Move")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Move")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Move")
	EMovementType MoveType = EMovementType::Static;

};

UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()

public:
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "GeometryData")
	FGeometryData GeometryData;

	//UPROPERTY(EditAnywhere, Category = "Weapon")
	//int32 WeaponsNum = 3;

	//UPROPERTY(EditDefaultsOnly, Category = "Stat")
	//int32 KillNum = 7;

	//UPROPERTY(EditInstanceOnly, Category = "Health")
	//float Health = 34.3454543f;

	//UPROPERTY(EditAnywhere, Category = "Health")
	//bool IsDead = false;

	//UPROPERTY(VisibleAnywhere, Category = "Weapon")
	//bool HasWeapon = true;

public:
	virtual void Tick(float DeltaTime) override;

private:
	//void PrintTypes();
	//void PrintStringTypes();
	//void PrintTransform();

	FVector InitialLocation;
	void HandleMovement();
};