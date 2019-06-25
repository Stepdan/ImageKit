#pragma once

#include <memory>

#include <QWidget>

namespace Ui {
class WorkspaceWidget;
}

namespace ImageKit::Interfaces {
class IPlugin;
}

namespace ImageKit {

class WorkspaceWidget : public QWidget
{
	Q_OBJECT

public:
	explicit WorkspaceWidget(QWidget *parent = nullptr);
	~WorkspaceWidget();

private slots:
	void OnSetPluginWidget(QWidget*);

private:
	std::unique_ptr<Ui::WorkspaceWidget> m_ui;
};

}
