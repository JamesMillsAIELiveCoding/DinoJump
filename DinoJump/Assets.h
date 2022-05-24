#pragma once

#include <map>

struct Texture2D;

struct Assets
{
public:
	static void Load();
	static Texture2D GetTexture(const char* _id);

private:
	static void LoadTextures();
	static std::map<const char*, Texture2D> textures;

};