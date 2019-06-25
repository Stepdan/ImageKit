#include <QRadioButton>
#include <QGroupBox>

#include "CustomElements/IntFieldSpinBox.h"
#include "CustomElements/DoubleFieldSpinBox.h"

#include "EffectsSettings.h"

namespace ImageKit { namespace EffectsSettings {

namespace {

template <typename T>
void CreateIntFieldSpinBox(QBoxLayout *layout, const QString &name, int value, T t)
{
	auto *field = new IntFieldSpinBox();

	field->setObjectName(name + "EffectsPanelIntField");
	field->SetName(name);
	field->SetValue(value);

	layout->addWidget(field);

	QObject::connect(field, &IntFieldSpinBox::valueChanged, [t, field]() { t(field->GetValue()); });
}

//.............................................................................

template <typename T>
void CreateDoubleFieldSpinBox(QBoxLayout *layout, const QString &name, double value, T t)
{
	auto *field = new DoubleFieldSpinBox();

	field->setObjectName(name + "EffectsPanelDoubleField");
	field->SetName(name);
	field->SetValue(value);

	layout->addWidget(field);

	QObject::connect(field, &DoubleFieldSpinBox::valueChanged, [t, field]() { t(field->GetValue()); });
}

//.............................................................................

template <typename T>
void CreateRadio(QBoxLayout *layout, const QString &name, const std::vector<QString> &names, int minValue, int value, T t)
{
	QVBoxLayout *vbox = new QVBoxLayout;
	for (size_t i = 0, sz = names.size(); i < sz; ++i)
	{
		auto *button = new QRadioButton(names[i]);
		if (static_cast<int>(i) == value - minValue)
			button->setChecked(true);

		QObject::connect(button, &QRadioButton::toggled, [t, minValue, i](bool checked) {if (checked) t(minValue + static_cast<int>(i)); });
		vbox->addWidget(button);
	}

	auto *group = new QGroupBox(name);
	group->setLayout(vbox);
	layout->addWidget(group);
}

//.............................................................................

template <typename T>
std::shared_ptr<T> CreateSettings()
{
	return std::make_shared<T>();
}

//.............................................................................


}

const SettingsCreatorList g_settingsCreator {
};

const SettingsCreatorList& GetSettingsCreatorList()
{
	return g_settingsCreator;
}

}}

