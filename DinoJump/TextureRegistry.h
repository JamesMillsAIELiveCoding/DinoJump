#pragma once

#include "AssetRegistry.h"

#include <raylib.h>

class TextureRegistry : public AssetRegistry<Texture2D>
{
public:
	TextureRegistry(string _path) : AssetRegistry(_path) {}

protected:
	virtual Texture2D LoadAsset(string _path) override;
	virtual void UnloadAsset(Texture2D _asset) override;

};

extern TextureRegistry textureRegistry;