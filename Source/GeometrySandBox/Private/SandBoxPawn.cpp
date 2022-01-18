
#include "SandBoxPawn.h"
#include "Components/InputComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogSandBoxPawn, All, All)

ASandBoxPawn::ASandBoxPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

void ASandBoxPawn::BeginPlay()
{
	Super::BeginPlay();

}

void ASandBoxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!VelocityVector.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;
		SetActorLocation(NewLocation);
	}
}

void ASandBoxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASandBoxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandBoxPawn::MoveRight);


}

void ASandBoxPawn::MoveForward(float Amount)
{
	UE_LOG(LogSandBoxPawn, Display, TEXT("Move forward: %f"), Amount);
	VelocityVector.X = Amount;
}

void ASandBoxPawn::MoveRight(float Amount)
{
	UE_LOG(LogSandBoxPawn, Display, TEXT("Move Right: %f"), Amount);
	VelocityVector.Y = Amount;
}

