#pragma once

#include "src/Proc/SettingsEffect/SettingsEffectBase.h"

namespace Proc::Interfaces {

class IEffect
{
public:
    virtual ~IEffect() = default;

    virtual const SettingsEffectBase & GetSettingsBase() const = 0;
    virtual void SetSettingsEffectBase(const SettingsEffectBase & settings) = 0;
};

}
