#include "Config.h"

#include <fstream>
#include <sstream>

Config config;

using std::ifstream;
using std::ios;

int Config::GetIntValue(const char* _category, const char* _id)
{
	return atoi(values[_category][_id].c_str());
}

float Config::GetFloatValue(const char* _category, const char* _id)
{
	return atof(values[_category][_id].c_str());
}

const char* Config::GetTextValue(const char* _category, const char* _id)
{
	return values[_category][_id].c_str();
}

void Config::Load()
{
	ifstream configFile("config.cfg");

	std::string line;
	std::string lastGroup;

	while (std::getline(configFile, line))
	{
		if (line.length() == 0)
			continue;

		if (line[0] == '[')
		{
			std::string newLine = line;
			newLine.erase(0, 1);
			newLine.erase(newLine.end() - 1, newLine.end());
			lastGroup = newLine;
		}
		else
		{
			std::string id = line;
			size_t index = line.find_first_of('=');
			id.erase(index, id.length() - index);

			std::string val = line;
			val.erase(0, index + 1);

			values[lastGroup][id] = val;
		}
	}
}