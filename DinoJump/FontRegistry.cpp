#include "FontRegistry.h"

FontRegistry fontRegistry = FontRegistry("fonts");

void FontRegistry::UnloadAsset(Font _asset)
{
	UnloadFont(_asset);
}

Font FontRegistry::LoadAsset(string _path)
{
	return LoadFont(_path.c_str());
}