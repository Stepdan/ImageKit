#include "PluginWidget.h"
#include "ui_PluginWidget.h"

namespace ImageKit {

PluginWidget::PluginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PluginWidget)
{
	ui->setupUi(this);
}

PluginWidget::~PluginWidget() = default;

}
