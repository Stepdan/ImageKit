#include "DataImageQt.h"

namespace Core { namespace MediaTypes {

std::shared_ptr<IDataImage> DataImageQt::Create()
{
	return nullptr;
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageQt::Create(const Types::ImageInfo & info)
{
	return nullptr;
}

//.............................................................................

DataImageQt::DataImageQt()
{}

//.............................................................................

DataImageQt::DataImageQt(const DataImageQt & rhs)
{}

//.............................................................................

const Types::ImageInfo & DataImageQt::GetImageInfo() const noexcept
{
	return Types::ImageInfo();
}

//.............................................................................

uint8_t* DataImageQt::GetData()
{
	return nullptr;
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageQt::Copy(Types::CopyMode) const
{
	return nullptr;
}

}}
