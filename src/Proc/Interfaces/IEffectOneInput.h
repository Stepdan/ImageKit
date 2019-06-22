#pragma once

#include <memory>

#include "IEffect.h"

namespace Core::Interfaces {
class IDataImage;
}

namespace Proc::Interfaces {

class IEffectOneInput : virtual public IEffect
{
protected:
    virtual ~IEffectOneInput() = default;

public:
    virtual void Apply(std::shared_ptr<Core::Interfaces::IDataImage>& src) = 0;
};

}
