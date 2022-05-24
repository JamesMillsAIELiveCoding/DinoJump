#pragma once

#include <string>
#include <map>

struct Config
{
	int GetIntValue(const char* _category, const char* _id);
	float GetFloatValue(const char* _category, const char* _id);
	const char* GetTextValue(const char* _category, const char* _id);
	void Load();

private:
	std::map<std::string, std::map<std::string, std::string>> values;

};

extern Config config;