#pragma once

#include <memory>

#include <QObject>

#include "src/Application/ImageKitCore/Interfaces/IImageKitCore.h"

#include "src/Application/ImageKitPlugins/Interfaces/IImageKitActionHandler.h"
#include "src/Application/ImageKitPlugins/Interfaces/IPluginsController.h"

#include

namespace ImageKit::Interfaces {
class IPlugin;
}

namespace ImageKit {

class ControllerUI
    : public QObject
    , public Interfaces::IImageKitActionHandler
{
	Q_OBJECT
public:
	ControllerUI(QWidget* parent = nullptr);
	~ControllerUI();

public:
	void HandleImageKitAction(ImageKitAction&);

public:
	std::shared_ptr<ImageKit::Interfaces::IPlugin> GetActivePlugin() const;

private slots:
	void OnActivatePlugin(PluginType);

signals:
	void setPluginWidget(QWidget*);

private:
	std::shared_ptr<ImageKitCore::Interfaces::IImageKitCore> m_imageKitCore;

	std::unique_ptr<Interfaces::IPluginsController> m_pluginsController;
};

}
