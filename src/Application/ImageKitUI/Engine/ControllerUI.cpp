#include <cassert>
#include <functional>

#include "src/Util/ObjectsConnector.h"

#include "src/Application/ImageKitCore/Core/ImageKitCore.h"

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"
#include "src/Application/ImageKitPlugins/Interfaces/PluginType.h"

#include "src/Application/ImageKitPlugins/ImageKitFactory/ImageKitFactory.h"

#include "src/Application/ImageKitUI/Engine/PluginsController.h"
#include "src/Application/ImageKitUI/ObjectsConnectorID.h"

#include "ControllerUI.h"

using namespace ImageKitCore;
using namespace ImageKitCore::Interfaces;
using namespace ImageKit::Interfaces;

namespace ImageKit {

//.............................................................................

ControllerUI::ControllerUI(QWidget* parent)
    : m_imageKitCore(IImageKitCore::Create())
{
	Util::ObjectsConnector::registerEmitter(ObjectConnectorID::SET_PLUGIN_WIDGET, this, SIGNAL(setPluginWidget(QWidget*)));

	Util::ObjectsConnector::registerReceiver(ObjectConnectorID::ACTIVATE_PLUGIN, this, SLOT(OnActivatePlugin(PluginType)));

	PluginsList pluginsList({PluginType::Effects});
	m_pluginsController = std::make_unique<PluginsController>(pluginsList, parent);
	OnActivatePlugin(pluginsList.front());
}

//.............................................................................

ControllerUI::~ControllerUI() = default;

//.............................................................................

void ControllerUI::HandleImageKitAction(ImageKitAction&)
{

}

//.............................................................................

void ControllerUI::OnActivatePlugin(PluginType type)
{
	m_pluginsController->SetActivePlugin(type);
	emit setPluginWidget(m_pluginsController->GetActivePlugin()->GetPluginWidget());
}

}
