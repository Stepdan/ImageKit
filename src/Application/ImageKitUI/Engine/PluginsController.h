#pragma once

#include "src/Application/ImageKitPlugins/Interfaces/IPluginsController.h"

namespace ImageKit {

class PluginsController : public Interfaces::IPluginsController
{
public:
	PluginsController(const PluginsList& list, QWidget* parent = nullptr);
	~PluginsController();

public:
	std::shared_ptr<Interfaces::IPlugin> GetActivePlugin() const;
	void SetActivePlugin(PluginType);

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}
