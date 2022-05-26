#pragma once

#include <raylib.h>
#include <string>
#include <map>
#include <filesystem>

using std::map;
using std::string;

namespace fs = std::filesystem;

typedef string AssetID;

template<typename REGISTRY_ITEM>
class AssetRegistry
{
public:
	AssetRegistry(string _path);
	REGISTRY_ITEM GetAsset(AssetID _id) const;
	void Load();
	void Unload();
	
protected:
	virtual void UnloadAsset(REGISTRY_ITEM _asset) = 0;
	virtual REGISTRY_ITEM LoadAsset(string _path) = 0;

private:
	string m_assetFolder;
	map<AssetID, REGISTRY_ITEM> m_registry;

};

template<typename REGISTRY_ITEM>
inline AssetRegistry<REGISTRY_ITEM>::AssetRegistry(string _assetFolder)
	: m_assetFolder(_assetFolder)
{
}

template<typename REGISTRY_ITEM>
inline REGISTRY_ITEM AssetRegistry<REGISTRY_ITEM>::GetAsset(AssetID _id) const
{
	if (m_registry.find(_id) != m_registry.end())
	{
		return m_registry.at(_id);
	}
}

template<typename REGISTRY_ITEM>
inline void AssetRegistry<REGISTRY_ITEM>::Load()
{
	string assetsFolder = "\\assets\\";

	fs::path current = fs::current_path();
	current.concat(assetsFolder.begin(), assetsFolder.end());
	current.concat(m_assetFolder.begin(), m_assetFolder.end());
	for (const auto& entry : fs::directory_iterator(current.c_str()))
	{
		string filePath = entry.path().u8string();
		string fileName = filePath;

		size_t index = fileName.find_last_of('\\') + 1;
		fileName = fileName.erase(0, index);
		index = fileName.find_last_of('.');
		fileName = fileName.erase(index, fileName.size() - index);

		m_registry[fileName] = LoadAsset(filePath);
	}
}

template<typename REGISTRY_ITEM>
inline void AssetRegistry<REGISTRY_ITEM>::Unload()
{
	for (auto& element : m_registry)
	{
		UnloadAsset(element.second);
	}
	
	m_registry.clear();
}
