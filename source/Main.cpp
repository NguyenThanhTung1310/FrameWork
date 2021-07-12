#include <stdio.h>
#include "esUtil.h"
#include "log.h"
#include "define.h"
#include "VideoDriver.h"
#include <crtdbg.h>
#include "SceneManager.h"
#include "Object.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Plane.h"
#include "CollisionManager.h"
#include <iostream>



#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
float cursorPos[2];
SceneManager *sceneManager = new SceneManager();
CollisionManager *collisionManager = new CollisionManager();

void PaintObject()
{
	// Limit FPS
	DWORD start, end;
	start = GetTickCount();
	// Render something here
	//VideoDriver::GetInstance()->CleanScreen();
	/*VideoDriver::GetInstance()->DrawCircle(100.0f, 100.0f, 100.0f);
	VideoDriver::GetInstance()->FillRect(0, 0, 100, 100);*/
	// Limit FPS
	sceneManager->Render();
	end = GetTickCount();
	DWORD frameTime = end - start;
	if (frameTime < 1000.0 / LIMIT_FPS)
		Sleep(1000 / LIMIT_FPS - frameTime);

}

bool InitGraphics(int w, int h)
{
	// Init scene
	LOGI("Initializing...");
	glViewport(0, 0, w, h);
	LOGI("Done!");
	return true;
}

void TouchActionDown(ESContext *esContext, int x, int y)
{

	// Mouse down
	sceneManager->handlingObjectClicked(x, y);
}

void TouchActionUp(ESContext *esContext, int x, int y)
{
	// Mouse up
	sceneManager->handlingObjectReleased(x, y);
}

void TouchActionMove(ESContext *esContext, int x, int y)
{
	// Mouse move
	cursorPos[0] = x;
	cursorPos[1] = y;
	sceneManager->handlingObjectMove(x, y);
}

void KeyDown(ESContext *ESContext, unsigned char keyCode, int x, int y)
{
	switch (keyCode)
	{
	case 'W':
	case 'w':
		break;
	case 'S':
	case 's':
		break;
	case 'A':
	case 'a':
		break;
	case 'D':
	case 'd':
		break;
	}
}

void KeyUp(ESContext *ESContext, unsigned char keyCode, int x, int y)
{
	switch (keyCode)
	{
	case 'W':
	case 'w':
		break;
	case 'S':
	case 's':
		break;
	case 'A':
	case 'a':
		break;
	case 'D':
	case 'd':
		break;
	}
}

void GameUpdate(ESContext *esContext, float deltaTime)
{
	// Update scene
	VideoDriver::GetInstance()->CleanScreen();
	collisionManager->checkAllCollision(sceneManager->objList);
	sceneManager->Update(deltaTime);
}

void GameDraw(ESContext *esContext)
{
	// Draw scene then swap buffer to display to screen
	PaintObject();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void GameExit()
{
	// Cleanup memory here
}

int main(int argc, char *argv[])
{
	sceneManager->Init();
	ESContext esContext;
	esInitContext(&esContext);

	esCreateWindow(&esContext, "Framework", (int)SCREEN_W, (int)SCREEN_H, ES_WINDOW_RGB);
	if (!InitGraphics((int)SCREEN_W, (int)SCREEN_H))
		return 0;

	esRegisterDrawFunc(&esContext, GameDraw);
	esRegisterKeyDownFunc(&esContext, KeyDown);
	esRegisterKeyUpFunc(&esContext, KeyUp);
	esRegisterUpdateFunc(&esContext, GameUpdate);
	esRegisterMouseDownFunc(&esContext, TouchActionDown);
	esRegisterMouseUpFunc(&esContext, TouchActionUp);
	esRegisterMouseMoveFunc(&esContext, TouchActionMove);
	esMainLoop(&esContext);
	GameExit();
}