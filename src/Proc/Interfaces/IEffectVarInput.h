#pragma once

#include <memory>
#include <vector>

#include "IEffect.h"

namespace Core::Interfaces {
class IDataImage;
}

namespace Proc::Interfaces {

class IEffectVarInput : virtual public IEffect
{
protected:
    virtual ~IEffectVarInput() = default;

public:
    virtual std::shared_ptr<Core::Interfaces::IDataImage> Apply(std::vector<std::shared_ptr<Core::Interfaces::IDataImage>>& src) = 0;
};

}
