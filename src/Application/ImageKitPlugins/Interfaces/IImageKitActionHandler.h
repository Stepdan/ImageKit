#pragma once

#include "ImageKitAction.h"

namespace ImageKit::Interfaces {

class IImageKitActionHandler
{
public:
    virtual ~IImageKitActionHandler() = default;

    virtual void HandleImageKitAction(const ImageKitAction &) = 0;
};

}
