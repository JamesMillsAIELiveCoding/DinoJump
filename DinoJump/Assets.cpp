#include "Assets.h"

#include <raylib.h>

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::map<string, Texture2D> Assets::textures;

void Assets::Load()
{
	LoadTextures();
}

void Assets::LoadTextures()
{
	string path = "\\assets\\textures";
	fs::path current = fs::current_path();
	current.concat(path.begin(), path.end());
	for (const auto& entry : fs::directory_iterator(current.c_str()))
	{
		string filePath = entry.path().u8string();
		string fileName = filePath;

		size_t index = fileName.find_last_of('\\') + 1;
		fileName = fileName.erase(0, index);
		index = fileName.find_last_of('.');
		fileName = fileName.erase(index, fileName.size() - index);

		textures[fileName] = LoadTexture(filePath.c_str());
	}
}

Texture2D Assets::GetTexture(const char* _id)
{
	return textures[_id];
}