#include <functional>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"
#include "src/Application/ImageKitPlugins/Interfaces/PluginType.h"

#include "src/Application/ImageKitPlugins/ImageKitFactory/ImageKitFactory.h"

#include "ControllerUI.h"

using namespace ImageKit::Interfaces;

namespace ImageKit {

class ControllerUI::PluginsControllerImpl : public QObject
{
	Q_OBJECT
public:
	PluginsControllerImpl(const PluginsList & list, QWidget* parent = nullptr)
	{
		std::transform(list.cbegin(), list.cend(), std::back_inserter(m_plugins), std::bind(&CreatePlugin, std::placeholders::_1, parent));
	}

private:
	std::vector<std::unique_ptr<IPlugin>> m_plugins;
};

//.............................................................................

ControllerUI::ControllerUI(QWidget* parent)
{

}

//.............................................................................

ControllerUI::~ControllerUI() = default;

}
