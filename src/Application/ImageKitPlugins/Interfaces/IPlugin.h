#pragma once

#include <string>

#include "PluginType.h"

class QToolButton;
class QWidget;

namespace ImageKit { namespace Interfaces {

class IPlugin
{
public:
    virtual ~IPlugin() = default;

	virtual PluginType GetPluginType() const noexcept = 0;
	virtual QWidget* GetPluginWidget() const = 0;
	virtual QToolButton* GetPluginButton() const = 0;
};

}}
