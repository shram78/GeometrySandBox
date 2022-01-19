
#include "GeometrySandBoxGameModeBase.h"
#include "SandBoxPawn.h"
#include "SceneBoxPlayerController.h"

AGeometrySandBoxGameModeBase::AGeometrySandBoxGameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
	PlayerControllerClass = ASceneBoxPlayerController::StaticClass();
}
