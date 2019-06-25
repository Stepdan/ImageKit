#pragma once

#include <memory>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

namespace ImageKit {

std::shared_ptr<Interfaces::IPlugin> CreatePlugin(PluginType type, QWidget* parent = nullptr);

}
