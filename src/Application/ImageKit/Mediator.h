#pragma once

#include <memory>

#include <QObject>

#include "src/Application/ImageKit/MainWindow.h"

namespace ImageKit {

class ControllerUI;

class Mediator : public QObject
{
	Q_OBJECT
public:
	Mediator(const std::shared_ptr<MainWindow> mainWindow);

private:
	std::shared_ptr<MainWindow> m_mainWindow;

	std::unique_ptr<ControllerUI> m_controllerUI;
};

}
