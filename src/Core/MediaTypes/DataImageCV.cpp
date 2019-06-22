#include "DataImageCV.h"

namespace Core::MediaTypes {

std::shared_ptr<IDataImage> DataImageCV::Create()
{
    return nullptr;
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageCV::Create(const Types::ImageInfo & info)
{
    return nullptr;
}

//.............................................................................

DataImageCV::DataImageCV()
{}

//.............................................................................

DataImageCV::DataImageCV(const DataImageCV & rhs)
{}

//.............................................................................

const Types::ImageInfo & DataImageCV::GetImageInfo() const noexcept
{
    return Types::ImageInfo();
}

//.............................................................................

uint8_t* DataImageCV::GetData()
{
    return nullptr;
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageCV::Copy(Types::CopyMode) const
{
    return nullptr;
}

}
