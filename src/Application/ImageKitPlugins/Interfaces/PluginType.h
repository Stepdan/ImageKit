#pragma once

#include <vector>

namespace ImageKit {

enum class PluginType
{
	Default = 0,
	Effects,
};

using PluginsList = std::vector<PluginType>;

}
