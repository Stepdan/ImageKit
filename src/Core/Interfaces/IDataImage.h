#pragma once

#include <cstdint>
#include <memory>

#include "src/Core/Types/CopyMode.h"
#include "src/Core/Types/ImageInfo.h"

namespace Core::Interfaces {

class IDataImage
{
public:
    virtual ~IDataImage() = default;

    virtual const Types::ImageInfo & GetImageInfo() const noexcept = 0;
    virtual uint8_t* GetData() = 0;
	virtual const uint8_t* GetData() const = 0;
    virtual std::shared_ptr<IDataImage> Copy(Types::CopyMode) const = 0;
};

}
