#pragma once

#include <QToolButton>

#include "src/Application/ImageKitPlugins/Interfaces/PluginType.h"

namespace ImageKit
{

class PluginButton : public QToolButton
{
	Q_OBJECT
public:
	explicit PluginButton(PluginType type, QWidget* parent = nullptr);

signals:
	void activatePlugin(PluginType);

private:
	PluginType m_type;
};

}
