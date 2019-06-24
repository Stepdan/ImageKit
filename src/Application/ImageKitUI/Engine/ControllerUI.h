#pragma once

#include <memory>

#include <QObject>

#include "src/Application/ImageKitPlugins/Interfaces/IImageKitActionHandler.h"

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

private:
	class PluginsControllerImpl;
	std::unique_ptr<PluginsControllerImpl> m_pluginsController;
};

}
