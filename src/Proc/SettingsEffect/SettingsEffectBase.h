#pragma once

#include <string>

namespace Proc {

class SettingsEffectBase
{
public:
	virtual ~SettingsEffectBase() = default;
	virtual const std::string & GetSettingsID() const = 0;

protected:
	SettingsEffectBase() = default;
};

#define PROC_SETTINGS(SettingsID) \
	static const std::string SETTINGS_ID;\
	const std::string & GetSettingsID() const { return SETTINGS_ID; }

}
