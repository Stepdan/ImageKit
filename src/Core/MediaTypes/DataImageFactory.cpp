#include "DataImageCV.h"
#include "DataImageQt.h"

#include "DataImageFactory.h"

namespace Core { namespace MediaTypes {

std::shared_ptr<IDataImage> DataImageFactory::CreateDataImage(const Types::ImageInfo & info, DataImageImpl impl /*= DataImageImpl::OpenCV*/)
{
	switch(impl)
	{
	case DataImageImpl::OpenCV:
		return DataImageCV::Create(info);

	case DataImageImpl::Qt:
		return DataImageQt::Create(info);
	}
}

}}
