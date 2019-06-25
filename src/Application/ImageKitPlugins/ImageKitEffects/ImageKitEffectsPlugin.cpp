#include <QPointer>
#include <QToolButton>
#include <QWidget>

#include "src/Application/ImageKitPlugins/Interfaces/ImageKitAction.h"
#include "src/Application/ImageKitPlugins/ImageKitUtil/UI/PluginButton.h"

#include "UI/ImageKitEffectsWidget.h"

#include "ImageKitEffectsPlugin.h"

namespace ImageKit{

class ImageKitEffectsPlugin::Impl : public QObject
{
	Q_OBJECT

public:
	Impl(QWidget* parent = nullptr)
	    : m_widget(new ImageKitEffectsWidget(parent))
	    , m_button(new PluginButton(PluginType::Effects, parent))
	{}

	QToolButton* GetButton() const { return m_button; }
	QWidget* GetWidget() const { return m_widget; }

private:
	QPointer<QWidget> m_widget;
	QPointer<QToolButton> m_button;
};

//.............................................................................

ImageKitEffectsPlugin::ImageKitEffectsPlugin(QWidget* parent)
    : m_impl(new Impl(parent))
{
}

//.............................................................................

ImageKitEffectsPlugin::~ImageKitEffectsPlugin() = default;

//.............................................................................

PluginType ImageKitEffectsPlugin::GetPluginType() const noexcept
{
	return PluginType::Effects;
}

//.............................................................................

QWidget* ImageKitEffectsPlugin::GetPluginWidget() const
{
	return m_impl ? m_impl->GetWidget() : nullptr;
}

//.............................................................................

QToolButton* ImageKitEffectsPlugin::GetPluginButton() const
{
	return m_impl ? m_impl->GetButton() : nullptr;
}

}
