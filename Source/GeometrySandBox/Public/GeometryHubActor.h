
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.h"
#include "GeometryHubActor.generated.h"


USTRUCT(BlueprintType)
struct FGeometryPayload
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseGeometryActor> GeometryClass;

	UPROPERTY(EditAnywhere)
	FGeometryData Data;

	UPROPERTY(EditAnywhere)
	FTransform InitialTransform;

};

UCLASS()
class GEOMETRYSANDBOX_API AGeometryHubActor : public AActor
{
	GENERATED_BODY()

public:
	AGeometryHubActor();

protected:
	virtual void BeginPlay() override;

	//создать объект BaseGeometry или его наследник, например блюпринт
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseGeometryActor> GeometryClass;

	UPROPERTY(EditAnywhere)
	TArray<FGeometryPayload> GeometryPayloads;

public:
	virtual void Tick(float DeltaTime) override;

private:
void DoActorSpawn1();

void DoActorSpawn2();

void DoActorSpawn3();
};
