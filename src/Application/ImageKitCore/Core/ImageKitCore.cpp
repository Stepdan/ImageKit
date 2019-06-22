#include "ImageKitCore.h"

namespace ImageKitCore {

std::shared_ptr<IImageKitCore> IImageKitCore::Create()
{
	std::shared_ptr<IImageKitCore> obj(new ImageKitCore(), ImageKitCoreDeleter());
	return obj;
}

//.............................................................................

ImageKitCore::ImageKitCore()
{
}

//.............................................................................

ImageKitCore::~ImageKitCore() = default;

//.............................................................................

IImageKitEffectApplier& ImageKitCore::GetEffectApplierEngine()
{
	return *this;
}

//.............................................................................

IImageKitIO& ImageKitCore::GetIOEngine()
{
	return *this;
}

//.............................................................................

IImageKitUndo& ImageKitCore::GetUndoEngine()
{
	return *this;
}

//.............................................................................

const std::shared_ptr<IDataImage> & ImageKitCore::GetDataImage() const
{
	return m_dataImage;
}

}
