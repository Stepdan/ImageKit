#pragma once

#include "ImageKitAction.h"

namespace ImageKit::Interfaces {

class IImageKitActionRequester
{
public:
    virtual ~IImageKitActionRequester() = default;

    virtual void Notify(const ImageKitAction &) const noexcept = 0;
};

}
