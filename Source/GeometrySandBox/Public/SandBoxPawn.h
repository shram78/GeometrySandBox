
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SandBoxPawn.generated.h"

UCLASS()
class GEOMETRYSANDBOX_API ASandBoxPawn : public APawn
{
	GENERATED_BODY()

public:
	ASandBoxPawn();

	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere)
		float Velocity = 300.0f;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector VelocityVector = FVector::ZeroVector;

	void MoveForward(float Amount);

	void MoveRight(float Amount);

};
