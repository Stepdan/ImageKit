#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class UndoWidget;
}

namespace ImageKit {

class UndoWidget : public QWidget
{
	Q_OBJECT

public:
	explicit UndoWidget(QWidget *parent = nullptr);
	~UndoWidget();

private:
	std::unique_ptr<Ui::UndoWidget> m_ui;
};

}
