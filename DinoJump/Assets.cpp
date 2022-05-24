#include "Assets.h"

#include <raylib.h>

std::map<const char*, Texture2D> Assets::textures;

void Assets::Load()
{
	LoadTextures();
}

void Assets::LoadTextures()
{
	textures["dino_death"] = LoadTexture("assets/dino_death.png");
	textures["dino_duck"] = LoadTexture("assets/dino_duck.png");
	textures["dino_run"] = LoadTexture("assets/dino_run.png");
	textures["flying_dino_evil"] = LoadTexture("assets/flying_dino_evil.png");
	textures["game_over"] = LoadTexture("assets/game_over.png");
	textures["ground"] = LoadTexture("assets/ground.png");
	textures["large_cacti"] = LoadTexture("assets/large_cacti.png");
	textures["small_cacti"] = LoadTexture("assets/small_cacti.png");
	textures["reset_button"] = LoadTexture("assets/reset_button.png");
}

Texture2D Assets::GetTexture(const char* _id)
{
	return textures[_id];
}