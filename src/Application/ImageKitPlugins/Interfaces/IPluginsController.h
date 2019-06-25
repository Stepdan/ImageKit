#pragma once

#include <memory>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

namespace ImageKit::Interfaces {

class IPluginsController
{
public:
	virtual ~IPluginsController() = default;

	virtual std::shared_ptr<IPlugin> GetActivePlugin() const = 0;
	virtual void SetActivePlugin(PluginType) = 0;
};

}
