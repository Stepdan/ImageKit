#include "src/Util/ObjectsConnector.h"

#include "src/Application/ImageKitPlugins/Interfaces/IPlugin.h"

#include "src/Application/ImageKitUI/ObjectsConnectorID.h"

#include "WorkspaceWidget.h"
#include "ui_WorkspaceWidget.h"

namespace ImageKit {

WorkspaceWidget::WorkspaceWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WorkspaceWidget)
{
	m_ui->setupUi(this);

	Util::ObjectsConnector::registerReceiver(ObjectConnectorID::SET_PLUGIN_WIDGET, this, SLOT(OnSetPluginWidget(QWidget*)));
}

//.............................................................................

WorkspaceWidget::~WorkspaceWidget() = default;

//.............................................................................

void WorkspaceWidget::OnSetPluginWidget(QWidget* widget)
{
	m_ui->pluginPanel = widget;
}

//.............................................................................

}
