#include "src/Util/ObjectsConnector.h"

#include "src/Application/ImageKitPlugins/Interfaces/ObjectConnectorID.h"

#include "ImageKitActionHandlerList.h"

namespace ImageKit {

ImageKitActionHandlerList::ImageKitActionHandlerList()
{
	Util::ObjectsConnector::registerReceiver(Interfaces::ObjectConnectorID::REGISTER_IMAGE_KIT_ACTION_HANDLER	, this, SLOT(RegisterHandler(IImageKitActionHandler*)));
	Util::ObjectsConnector::registerReceiver(Interfaces::ObjectConnectorID::UNREGISTER_IMAGE_KIT_ACTION_HANDLER	, this, SLOT(UnregisterHandler(IImageKitActionHandler*)));
	Util::ObjectsConnector::registerReceiver(Interfaces::ObjectConnectorID::NOTIFY_IMAGE_KIT_ACTION				, this, SLOT(OnNotify(ImageKitAction&)));
}

//.............................................................................

void ImageKitActionHandlerList::RegisterHandler(IImageKitActionHandler* handler)
{
	if(!handler)
		return;

	if(std::find(m_handlerList.cbegin(), m_handlerList.cend(), handler) == m_handlerList.cend())
		m_handlerList.push_back(handler);
}

//.............................................................................

void ImageKitActionHandlerList::UnregisterHandler(IImageKitActionHandler* handler)
{
	if(!handler)
		return;

	auto it = std::find(m_handlerList.cbegin(), m_handlerList.cend(), handler);
	if(it != m_handlerList.cend())
		m_handlerList.erase(it);
}

//.............................................................................

void ImageKitActionHandlerList::OnNotify(ImageKitAction& action)
{
	for(const auto & handler : m_handlerList)
		handler->HandleImageKitAction(action);
}

}
