#include "WorkspaceWidget.h"
#include "ui_WorkspaceWidget.h"

namespace ImageKit {

WorkspaceWidget::WorkspaceWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WorkspaceWidget)
{
	m_ui->setupUi(this);
}

WorkspaceWidget::~WorkspaceWidget() = default;

}
