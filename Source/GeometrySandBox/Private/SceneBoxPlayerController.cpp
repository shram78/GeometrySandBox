
#include "SceneBoxPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SandBoxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogSceneBoxPlayerController, All, All)

void ASceneBoxPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASceneBoxPlayerController::ChangePawn);
	}
}

void ASceneBoxPlayerController::BeginPlay()
{
	Super::BeginPlay();


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASandBoxPawn::StaticClass(), Pawns);
}

void ASceneBoxPlayerController::ChangePawn()
{
	if (Pawns.Num() <= 1) return;

	ASandBoxPawn* CurrentPawn = Cast<ASandBoxPawn>(Pawns[CurrentPawnIndex]);
	CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();
	if (!CurrentPawn) return;

	UE_LOG(LogSceneBoxPlayerController, Error, TEXT("Change player pawn"));
	Possess(CurrentPawn);

}
