#pragma once

#include "src/Core/Types/ImageInfo.h"

#include "src/Core/Interfaces/DataImageImpl.h"
#include "src/Core/Interfaces/IDataImage.h"

using namespace Core::Interfaces;

namespace Core::MediaTypes {

class DataImageFactory
{
public:
    static std::shared_ptr<IDataImage> CreateDataImage(const Types::ImageInfo & info, DataImageImpl impl = DataImageImpl::OpenCV);
};

}
