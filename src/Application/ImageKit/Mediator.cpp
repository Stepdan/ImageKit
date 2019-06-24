#include "src/Application/ImageKitUI/Engine/ControllerUI.h"

#include "Mediator.h"

namespace ImageKit {

Mediator::Mediator(const std::shared_ptr<MainWindow> mainWindow)
    : m_mainWindow(mainWindow)
    , m_controllerUI(new ControllerUI(m_mainWindow.get()))
{
}


}
