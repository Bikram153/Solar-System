#include "YourGameModeBase.h"
#include "YourPlayerController.h"

AYourGameModeBase::AYourGameModeBase()
{
    PlayerControllerClass = AYourPlayerController::StaticClass();
}
