#pragma once

#include <memory>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

//TODO Генерируемый тип плагина

namespace ImageKit {

std::unique_ptr<Interfaces::IPlugin> CreatePlugin(/*PluginType*/);

}
