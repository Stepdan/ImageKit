#pragma once

#include <string>

#include "IImageKitActionRequester.h"

class QToolButton;
class QWidget;

namespace ImageKit { namespace Interfaces {

class IPlugin : virtual public IImageKitActionRequester
{
public:
    virtual ~IPlugin() = default;

    virtual const std::string & GetPluginName() const  = 0;
    virtual QWidget* GetPluginWidget() const = 0;
    virtual QToolButton* GetPluginButton() const = 0;
};

}}
