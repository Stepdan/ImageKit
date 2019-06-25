#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class IntFieldSpinBox;
}

namespace ImageKit {

class IntFieldSpinBox : public QWidget
{
	Q_OBJECT

public:
	explicit IntFieldSpinBox(QWidget *parent = nullptr);
	~IntFieldSpinBox();

	void SetName(const QString &);
	void SetValue(int);
	double GetValue() const;

signals:
	void valueChanged(int);

private:
	std::unique_ptr<Ui::IntFieldSpinBox> m_ui;
};

}
