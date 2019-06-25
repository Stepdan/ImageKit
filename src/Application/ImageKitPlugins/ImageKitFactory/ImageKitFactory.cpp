#include <cassert>

#include "src/Application/ImageKitPlugins/ImageKitEffects/ImageKitEffectsPlugin.h"

#include "ImageKitFactory.h"

namespace ImageKit {

std::shared_ptr<Interfaces::IPlugin> CreatePlugin(PluginType type, QWidget* parent)
{
	switch(type)
	{
	    case PluginType::Effects:
		    return std::make_shared<ImageKitEffectsPlugin>(parent);

	    default:
		    assert(!"ImageKitFactory:: Incorrect plugin type!");
		    return nullptr;
	}
}

}
