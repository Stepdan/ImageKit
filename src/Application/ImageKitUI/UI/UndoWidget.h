#pragma once

#include <memory>

#include <QWidget>

#include "src/Application/ImageKitPlugins/Interfaces/ActionType.h"

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

signals:
	void notify(ActionType);

private:
	std::unique_ptr<Ui::UndoWidget> m_ui;
};

}
