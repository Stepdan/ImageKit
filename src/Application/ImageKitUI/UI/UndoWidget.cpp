#include <functional>

#include "src/Util/ObjectsConnector.h"

#include "src/Application/ImageKitPlugins/Interfaces/ObjectConnectorID.h"

#include "UndoWidget.h"
#include "ui_UndoWidget.h"

namespace ImageKit {

UndoWidget::UndoWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::UndoWidget)
{
	m_ui->setupUi(this);

	Util::ObjectsConnector::registerEmitter(Interfaces::ObjectConnectorID::NOTIFY_IMAGE_KIT_ACTION, this, SIGNAL(notify(ImageKitAction)));

	connect(m_ui->undoButton	, &QAbstractButton::clicked, std::bind(&UndoWidget::notify, ImageKit::ActionType::Undo));
	connect(m_ui->redoButton	, &QAbstractButton::clicked, std::bind(&UndoWidget::notify, ImageKit::ActionType::Redo));
	connect(m_ui->resetButton	, &QAbstractButton::clicked, std::bind(&UndoWidget::notify, ImageKit::ActionType::Reset));
}

//.............................................................................

UndoWidget::~UndoWidget() = default;

}
