#pragma once

#include <memory>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

class QObject;

namespace ImageKit {

class ImageKitEffectsPlugin : public Interfaces::IPlugin
{
public:
	ImageKitEffectsPlugin(QWidget* parent = nullptr);
	~ImageKitEffectsPlugin();

public:
	PluginType GetPluginType() const noexcept override;
	QWidget* GetPluginWidget() const override;
	QToolButton* GetPluginButton() const override;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

}
