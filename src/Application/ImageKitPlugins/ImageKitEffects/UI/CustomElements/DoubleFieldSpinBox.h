#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class DoubleFieldSpinBox;
}

namespace ImageKit {

class DoubleFieldSpinBox : public QWidget
{
	Q_OBJECT

public:
	explicit DoubleFieldSpinBox(QWidget *parent = nullptr);
	~DoubleFieldSpinBox();

	void SetName(const QString &);
	void SetValue(double);
	double GetValue() const noexcept;

signals:
	void valueChanged(double);

private:
	std::unique_ptr<Ui::DoubleFieldSpinBox> m_ui;
};

}
