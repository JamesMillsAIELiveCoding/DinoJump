#include "SoundRegistry.h"

SoundRegistry soundRegistry = SoundRegistry("sounds");

void SoundRegistry::UnloadAsset(Sound _asset)
{
	UnloadSound(_asset);
}

Sound SoundRegistry::LoadAsset(string _path)
{
	return LoadSound(_path.c_str());
}