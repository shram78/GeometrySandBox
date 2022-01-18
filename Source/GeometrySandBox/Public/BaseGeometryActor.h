#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorChange, const FLinearColor&, Color, const FString&, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Design")
	FLinearColor Color = FLinearColor::Black;
	
	UPROPERTY(EditAnywhere, Category = "Design")
	float TimerRate = 3.0f;
};


UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()

public:
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	void SetGeometryData(const FGeometryData& Data){ GeometryData = Data;}

	UFUNCTION(BlueprintCallable)
	FGeometryData GetGeometryData() const {return GeometryData; }

	UPROPERTY(BlueprintAssignable)
	FOnColorChange OnColorChanged;

	FOnTimerFinished OnTimerFinished;

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GeometryData")
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
	FTimerHandle TimerHandle;

	const int32 MaxTimerCount = 5;
	int32 TimerCount = 0;

	void HandleMovement();

	void SetColor(const FLinearColor& Color);

	void OnTimerFired();
};