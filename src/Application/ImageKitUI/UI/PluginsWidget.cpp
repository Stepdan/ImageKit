#include "PluginsWidget.h"
#include "ui_PluginsWidget.h"

namespace ImageKit {

PluginsWidget::PluginsWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::PluginsWidget)
{
	m_ui->setupUi(this);
}

PluginsWidget::~PluginsWidget() = default;

}
