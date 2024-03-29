#pragma once

#include <memory>

#include "DataImageImpl.h"

namespace Core::Interfaces {

class IDataImage;

class IDataImageFactory
{
public:
	virtual ~IDataImageFactory() = default;

	virtual std::shared_ptr<IDataImage> CreateDataImage(DataImageImpl) const = 0;
};

}
