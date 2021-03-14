#include "GameWindows.h"
#include "GameGraphics.h"
#include "GameInput.h"
#include "GameStateManager.h"


//ken edited
//hello ken

//	use int main if you want to have a console to print out message 
int main()
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GameWindows* gWin = gWin->getInstance();
	gWin->createWindow();
	GameGraphics* gGraphics = gGraphics->getInstance();
	gGraphics->createDevice();
	GameInput* gInput = GameInput::getInstance();
	gInput->createInput();

	GameStateManager* gManager = gManager->getInstance();
	while (gWin->gameLoop())//it just works
	{
		gInput->update();

		gManager->update();
		gManager->fixedUpdate();

		gGraphics->beginScene();

		gManager->draw();
		gGraphics->endScene();
	}

	gInput->release();
	gGraphics->release();
	gWin->release();
	gManager->release();

	return 0;
}