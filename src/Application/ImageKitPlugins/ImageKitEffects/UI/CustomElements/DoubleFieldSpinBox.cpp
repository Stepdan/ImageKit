#include "DoubleFieldSpinBox.h"
#include "ui_DoubleFieldSpinBox.h"

namespace ImageKit {

DoubleFieldSpinBox::DoubleFieldSpinBox(QWidget *parent) :
	QWidget(parent),
    m_ui(new Ui::DoubleFieldSpinBox)
{
	m_ui->setupUi(this);

	connect(m_ui->spinBox, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DoubleFieldSpinBox::valueChanged);
}

//.............................................................................

DoubleFieldSpinBox::~DoubleFieldSpinBox() = default;

//.............................................................................

void DoubleFieldSpinBox::SetName(const QString & str)
{
	m_ui->label->setText(str);
}

//.............................................................................

void DoubleFieldSpinBox::SetValue(double value)
{
	m_ui->spinBox->setValue(value);
}

//.............................................................................

double DoubleFieldSpinBox::GetValue() const
{
	return m_ui->spinBox->value();
}

}
