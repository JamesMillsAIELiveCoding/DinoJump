#include "Application.h"

#include <raylib.h>
#include "RayGizmos.h"
#include <cstdlib>

#include "TextureRegistry.h"
#include "SoundRegistry.h"

#include "Config.h"
#include "GameStateManager.h"

#include "PlayState.h"

Application::Application()
{
    m_gameStateManager = new GameStateManager();
    windowWidth = config.GetIntValue(PROGRAM_CATEGORY, "width");
    windowHeight = config.GetIntValue(PROGRAM_CATEGORY, "height");
}

Application::~Application()
{
    delete m_gameStateManager;
}

void Application::Load()
{
    InitWindow(windowWidth, windowHeight, config.GetTextValue(PROGRAM_CATEGORY, "name"));
    SetTargetFPS(60);

    textureRegistry.Load();
    soundRegistry.Load();
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

    RayGizmos::Draw();

    EndDrawing();
}

void Application::Unload()
{
    textureRegistry.Unload();
    soundRegistry.Unload();

	CloseWindow();
}

void Application::SetupStates()
{
    m_gameStateManager->SetState("Play", new PlayState(this));
    m_gameStateManager->PushState("Play");
}