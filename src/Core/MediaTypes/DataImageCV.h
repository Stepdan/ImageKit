#pragma once

#include <memory>

#include "src/Core/Interfaces/IDataImage.h"

using namespace Core::Interfaces;

namespace Core::MediaTypes {

class DataImageCV : public IDataImage
{
public:
    static std::shared_ptr<IDataImage> Create();
    static std::shared_ptr<IDataImage> Create(const Types::ImageInfo &);

private:
    DataImageCV();
    DataImageCV(const DataImageCV & rhs);
    ~DataImageCV() = default;

public:
    const Types::ImageInfo & GetImageInfo() const noexcept override;
    uint8_t* GetData() override;
    std::shared_ptr<IDataImage> Copy(Types::CopyMode) const override;

private:
    //todo impl;
};

}
