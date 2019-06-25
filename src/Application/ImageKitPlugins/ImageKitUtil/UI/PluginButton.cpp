#include <functional>

#include "src/Util/ObjectsConnector.h"

#include "src/Application/ImageKitUI/ObjectsConnectorID.h"

#include "PluginButton.h"

namespace ImageKit {

PluginButton::PluginButton(PluginType type, QWidget* parent)
    : QToolButton(parent)
    , m_type(type)
{
	Util::ObjectsConnector::registerEmitter(ObjectConnectorID::ACTIVATE_PLUGIN, this, SIGNAL(activatePlugin(PluginType)));

	connect(this, &QAbstractButton::clicked, std::bind(&PluginButton::activatePlugin, m_type));
}

}
