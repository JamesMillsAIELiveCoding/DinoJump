#include "TextureRegistry.h"

TextureRegistry textureRegistry = TextureRegistry("textures");

void TextureRegistry::UnloadAsset(Texture2D _asset)
{
	UnloadTexture(_asset);
}

Texture2D TextureRegistry::LoadAsset(string _path)
{
	return LoadTexture(_path.c_str());
}