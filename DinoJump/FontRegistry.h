#pragma once

#include "AssetRegistry.h"

#include <raylib.h>

class FontRegistry : public AssetRegistry<Font>
{
public:
	FontRegistry(string _path) : AssetRegistry(_path) {}

protected:
	virtual Font LoadAsset(string _path) override;
	virtual void UnloadAsset(Font _asset) override;

};

extern FontRegistry fontRegistry;