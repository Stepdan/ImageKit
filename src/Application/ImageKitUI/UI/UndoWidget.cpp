#include "UndoWidget.h"
#include "ui_UndoWidget.h"

namespace ImageKit {

UndoWidget::UndoWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::UndoWidget)
{
	m_ui->setupUi(this);
}

UndoWidget::~UndoWidget() = default;

}
