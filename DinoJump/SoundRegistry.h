#pragma once

#include "AssetRegistry.h"

#include <raylib.h>

class SoundRegistry : public AssetRegistry<Sound>
{
public:
	SoundRegistry(string _path) : AssetRegistry(_path) {}

protected:
	virtual void UnloadAsset(Sound _asset) override;
	virtual Sound LoadAsset(string _path) override;

};

extern SoundRegistry soundRegistry;