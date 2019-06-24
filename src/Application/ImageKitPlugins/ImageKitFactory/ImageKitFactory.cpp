#include <cassert>

#include "src/Application/ImageKitPlugins/ImageKitEffects/ImageKitEffectsPlugin.h"

#include "ImageKitFactory.h"

namespace ImageKit {

std::unique_ptr<Interfaces::IPlugin> CreatePlugin(PluginType type, QWidget* parent)
{
	switch(type)
	{
	    case PluginType::Effects:
		    return std::make_unique<ImageKitEffectsPlugin>(parent);

	    default:
		    assert(!"ImageKitFactory:: Incorrect plugin type!");
		    return nullptr;
	}
}

}
