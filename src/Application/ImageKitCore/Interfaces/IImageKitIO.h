#pragma once

#include <string>

namespace ImageKitCore::Interfaces {

class IImageKitIO
{
public:
    virtual ~IImageKitIO() = default;

    virtual void Load(const std::string & path) = 0;
    virtual void Save(const std::string & path) const = 0;

    virtual const std::string & GetSessionTempDir() const noexcept = 0;
};

}
