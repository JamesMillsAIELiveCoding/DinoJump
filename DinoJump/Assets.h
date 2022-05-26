#pragma once

#include <map>
#include <string>

using std::string;

struct Texture2D;

struct Assets
{
public:
	static void Load();
	static Texture2D GetTexture(const char* _id);

private:
	static void LoadTextures();
	static std::map<string, Texture2D> textures;

};