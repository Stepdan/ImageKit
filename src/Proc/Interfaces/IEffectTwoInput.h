#pragma once

#include <memory>

#include "IEffect.h"

namespace Core::Interfaces {
class IDataImage;
}

namespace Proc::Interfaces {

class IEffectTwoInput : virtual public IEffect
{
protected:
    virtual ~IEffectTwoInput() = default;

public:
    virtual void Apply(const std::shared_ptr<Core::Interfaces::IDataImage>& src1, std::shared_ptr<Core::Interfaces::IDataImage>& src2) = 0;
};

}
