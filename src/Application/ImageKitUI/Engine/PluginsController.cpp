#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>

#include "src/Application/ImageKitPlugins/ImageKitFactory/ImageKitFactory.h"

#include "PluginsController.h"

using namespace ImageKit::Interfaces;

namespace ImageKit {

class PluginsController::Impl
{
public:
	Impl(const PluginsList & list, QWidget* parent = nullptr)
	{
		assert(!list.empty());
		std::transform(list.cbegin(), list.cend(), std::back_inserter(m_plugins), std::bind(&CreatePlugin, std::placeholders::_1, parent));
		m_activePlugin = list.front();
	}

	std::shared_ptr<IPlugin> GetPlugin(PluginType type) const
	{
		const auto it = std::find_if(m_plugins.cbegin(), m_plugins.cend(), std::bind(std::equal_to<PluginType>(), std::bind(&IPlugin::GetPluginType, std::placeholders::_1), type));
		return it != m_plugins.cend() ? *it : nullptr;
	}

	std::shared_ptr<IPlugin> GetActivePlugin() const
	{
		return GetPlugin(m_activePlugin);
	}

	void SetActivePlugin(PluginType type)
	{
		m_activePlugin = type;
	}

private:
	std::vector<std::shared_ptr<IPlugin>> m_plugins;
	PluginType m_activePlugin;
};

//.............................................................................

PluginsController::PluginsController(const PluginsList & list, QWidget* parent)
    : m_impl(new Impl(list, parent))
{
}

//.............................................................................

PluginsController::~PluginsController() = default;

//.............................................................................

std::shared_ptr<Interfaces::IPlugin> PluginsController::GetActivePlugin() const
{
	return m_impl->GetActivePlugin();
}

//.............................................................................

void PluginsController::SetActivePlugin(PluginType type)
{
	m_impl->SetActivePlugin(type);
}

}
