#include "src/Proc/Interfaces/IEffectOneInput.h"
#include "src/Proc/Interfaces/IEffectTwoInput.h"
#include "src/Proc/Interfaces/IEffectVarInput.h"

#include "EffectsFactory.h"

namespace Proc {

EffectsFactory& EffectsFactory::Instance()
{
	static EffectsFactory obj;
	return obj;
}

//.............................................................................

EffectsFactory::EffectsFactory()
{
	//todo регистрация эффектов из cmake
}

//.............................................................................

std::shared_ptr<IEffectOneInput> EffectsFactory::CreateEffectOneInput(const std::string & settingsID) const
{
	const auto creatorIt = m_creators.OneInput.find(settingsID);
	if(creatorIt == m_creators.OneInput.cend())
		assert(!"EffectsFactory::CreateOneInputEffect: Incorrect settingsID");

	return creatorIt->second->Create();
}

//.............................................................................

std::shared_ptr<IEffectTwoInput> EffectsFactory::CreateEffectTwoInput(const std::string & settingsID) const
{
	const auto creatorIt = m_creators.TwoInput.find(settingsID);
	if(creatorIt == m_creators.TwoInput.cend())
		assert(!"EffectsFactory::CreateTwoInputEffect: Incorrect settingsID");

	return creatorIt->second->Create();
}

//.............................................................................

std::shared_ptr<IEffectVarInput> EffectsFactory::CreateEffectVarInput(const std::string & settingsID) const
{
	const auto creatorIt = m_creators.VarInput.find(settingsID);
	if(creatorIt == m_creators.VarInput.cend())
		assert(!"EffectsFactory::CreateVarInputEffect: Incorrect settingsID");

	return creatorIt->second->Create();
}

}
