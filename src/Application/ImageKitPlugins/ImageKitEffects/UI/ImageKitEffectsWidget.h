#pragma once

#include <memory>

#include <QWidget>

#include "src/Application/ImageKitPlugins/Interfaces/ImageKitAction.h"

namespace Ui {
class ImageKitEffectsWidget;
}

namespace Proc {
class SettingsEffectBase;
}

namespace ImageKit {

class ImageKitEffectsWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ImageKitEffectsWidget(QWidget *parent = 0);
	~ImageKitEffectsWidget();

signals:
	void notify(ImageKitAction&);

private:
	void OnOkClicked();
	void OnEffectChanged(int index);

private:
	std::unique_ptr<Ui::ImageKitEffectsWidget> m_ui;

	std::shared_ptr<Proc::SettingsEffectBase> m_settings;
};

}
