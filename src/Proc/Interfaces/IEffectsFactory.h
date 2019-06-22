#pragma once

#include <memory>
#include <string>

namespace Proc::Interfaces {

class IEffectOneInput;
class IEffectTwoInput;
class IEffectVarInput;

class IEffectsFactory
{
public:
    virtual ~IEffectsFactory() = default;

    virtual std::shared_ptr<IEffectOneInput> CreateEffectOneInput(const std::string & settingsID) const = 0;
    virtual std::shared_ptr<IEffectTwoInput> CreateEffectTwoInput(const std::string & settingsID) const = 0;
    virtual std::shared_ptr<IEffectVarInput> CreateEffectVarInput(const std::string & settingsID) const = 0;
};

}
