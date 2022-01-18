
#include "GeometrySandBoxGameModeBase.h"
#include "SandBoxPawn.h"

AGeometrySandBoxGameModeBase::AGeometrySandBoxGameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
}
