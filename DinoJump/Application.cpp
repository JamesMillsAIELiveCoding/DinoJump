#include "Application.h"

#include <raylib.h>
#include <cstdlib>

#include "Assets.h"
#include "Config.h"
#include "GameStateManager.h"

#include "PlayState.h"

Application::Application()
{
    m_gameStateManager = new GameStateManager();
}

Application::~Application()
{
    delete m_gameStateManager;
}

void Application::Load()
{
    config.Load();
    windowWidth = config.GetIntValue("Program", "width");
    windowHeight = config.GetIntValue("Program", "height");
    InitWindow(windowWidth, windowHeight, config.GetTextValue("Program", "name"));
    SetTargetFPS(60);

    Assets::Load();
    SetupStates();
}

void Application::Run()
{
    while (!WindowShouldClose())
    {
        Update(GetFrameTime());
        Draw();
    }
}

void Application::Update(float _dt)
{
    m_gameStateManager->Update(_dt);
}

void Application::Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    m_gameStateManager->Draw();

    EndDrawing();
}

void Application::Unload()
{
	CloseWindow();
}

void Application::SetupStates()
{
    m_gameStateManager->SetState("Play", new PlayState(this));
    m_gameStateManager->PushState("Play");
}