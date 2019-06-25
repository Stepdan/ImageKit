#include "IntFieldSpinBox.h"
#include "ui_IntFieldSpinBox.h"

namespace ImageKit {

IntFieldSpinBox::IntFieldSpinBox(QWidget *parent) :
	QWidget(parent),
    m_ui(new Ui::IntFieldSpinBox)
{
	m_ui->setupUi(this);

	connect(m_ui->spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &IntFieldSpinBox::valueChanged);
}

//.............................................................................

IntFieldSpinBox::~IntFieldSpinBox() = default;

//.............................................................................

void IntFieldSpinBox::SetName(const QString & str)
{
	m_ui->label->setText(str);
}

//.............................................................................

void IntFieldSpinBox::SetValue(int value)
{
	m_ui->spinBox->setValue(value);
}

//.............................................................................

double IntFieldSpinBox::GetValue() const
{
	return m_ui->spinBox->value();
}

}
