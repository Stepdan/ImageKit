#pragma once

#include <memory>

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

class QObject;

namespace ImageKit {

class ImageKitEffectsPlugin : public Interfaces::IPlugin
{
public:
    ImageKitEffectsPlugin(QObject* parent = nullptr);

public:
    void Notify(const ImageKitAction &) const noexcept override;

public:
    const std::string & GetPluginName() const override;
    QWidget* GetPluginWidget() const  override;
    QToolButton* GetPluginButton() const override;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

}
