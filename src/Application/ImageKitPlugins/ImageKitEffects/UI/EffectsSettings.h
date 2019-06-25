#pragma once

#include <memory>

#include <QBoxLayout>

#include "src/Proc/SettingsEffect/SettingsEffectBase.h"

namespace ImageKit { namespace EffectsSettings {

using SettingsCreator = std::shared_ptr<Proc::SettingsEffectBase>(*)(QBoxLayout*);
using SettingsCreatorList = std::vector<std::pair<QString, SettingsCreator>>;

const SettingsCreatorList& GetSettingsCreatorList();

}}
