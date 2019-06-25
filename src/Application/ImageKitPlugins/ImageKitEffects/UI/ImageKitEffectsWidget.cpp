#include <cassert>

#include <QObject>
#include <QSlider>
#include <QBoxLayout>

#include "src/Util/ObjectsConnector.h"

#include "src/Proc/SettingsEffect/SettingsEffectBase.h"

#include "src/Application/ImageKitPlugins/Interfaces/ObjectConnectorID.h"

#include "EffectsSettings.h"

#include "ImageKitEffectsWidget.h"
#include "ui_ImageKitEffectsWidget.h"

using namespace ImageKit::EffectsSettings;

namespace {

void ClearLayout(QLayout *layout)
{
	if(!layout)
		return;

	QLayoutItem* item;
	while((item = layout->takeAt(0)))
	{
		if (item->layout())
			ClearLayout(item->layout());
		else if (item->widget())
			delete item->widget();

		delete item;
	}
}

}

namespace ImageKit {

ImageKitEffectsWidget::ImageKitEffectsWidget(QWidget *parent) :
	QWidget(parent),
    m_ui(new Ui::ImageKitEffectsWidget)
{
	m_ui->setupUi(this);

	m_ui->comboBox->addItem("");
	for(const auto & item : GetSettingsCreatorList())
		m_ui->comboBox->addItem(item.first);

	connect(m_ui->comboBox, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, &ImageKitEffectsWidget::OnEffectChanged);
	connect(m_ui->okButton, &QAbstractButton::clicked, this, &ImageKitEffectsWidget::OnOkClicked);

	Util::ObjectsConnector::registerEmitter(Interfaces::ObjectConnectorID::NOTIFY_IMAGE_KIT_ACTION, this, SIGNAL(notify(ImageKitAction&)));
}

//.............................................................................

ImageKitEffectsWidget::~ImageKitEffectsWidget() = default;

//.............................................................................

void ImageKitEffectsWidget::OnOkClicked()
{
}

//.............................................................................

void ImageKitEffectsWidget::OnEffectChanged(int index)
{
	if(index < 0) return;

	auto layout = m_ui->scrollAreaContent->layout();
	ClearLayout(layout);
	auto settings = GetSettingsCreatorList()[index-1].second(qobject_cast<QBoxLayout*>(layout));
	qobject_cast<QBoxLayout*>(m_ui->scrollAreaContent->layout())->addStretch();

	m_settings = settings;
}

}
