#pragma once

#include "src/Proc/Interfaces/IEffectOneInput.h"
#include "src/Proc/Interfaces/IEffectTwoInput.h"
#include "src/Proc/Interfaces/IEffectVarInput.h"

namespace ImageKitCore::Interfaces {

class IImageKitEffectApplier
{
public:
    virtual ~IImageKitEffectApplier() = default;

public:
    enum class InputType { OneInput, TwoInput, VarInput };

public:
    virtual void ApplyEffect(const Proc::SettingsEffectBase & settingsBase, InputType type) = 0;
    virtual void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectOneInput> & effect) = 0;
    virtual void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectTwoInput> & effect) = 0;
    virtual void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectVarInput> & effect) = 0;
};

}
