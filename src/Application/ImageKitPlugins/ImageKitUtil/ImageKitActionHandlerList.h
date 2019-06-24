#pragma once

#include <QObject>

#include "src/Application/ImageKitPlugins/Interfaces/IImageKitActionHandler.h"

using namespace ImageKit::Interfaces;

namespace ImageKit {

// TODO Сделать шаблонным и многопоточным
class ImageKitActionHandlerList : public QObject
{
	Q_OBJECT
public:
	ImageKitActionHandlerList();

public slots:
	void RegisterHandler(IImageKitActionHandler*);
	void UnregisterHandler(IImageKitActionHandler*);

private slots:
	void OnNotify(ImageKitAction&);

private:
	std::vector<IImageKitActionHandler*> m_handlerList;
};

}
