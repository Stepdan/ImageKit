#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class PluginWidget;
}

namespace ImageKit {

class PluginWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PluginWidget(QWidget *parent = nullptr);
	~PluginWidget();

private:
	std::unique_ptr<Ui::PluginWidget> ui;
};

}
