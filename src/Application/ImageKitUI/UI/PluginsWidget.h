#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class PluginsWidget;
}

namespace ImageKit {

class PluginsWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PluginsWidget(QWidget *parent = nullptr);
	~PluginsWidget();

private:
	std::unique_ptr<Ui::PluginsWidget> m_ui;
};

}
