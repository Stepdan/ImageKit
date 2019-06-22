#pragma once

#include <cassert>

#include "src/Proc/Interfaces/IEffectsFactory.h"

#include "EffectCreator.h"

using namespace Proc::Interfaces;

namespace Proc {

class EffectsFactory : public IEffectsFactory
{
public:
	static EffectsFactory & Instance();

	std::shared_ptr<IEffectOneInput> CreateEffectOneInput(const std::string & settingsID) const override;
	std::shared_ptr<IEffectTwoInput> CreateEffectTwoInput(const std::string & settingsID) const override;
	std::shared_ptr<IEffectVarInput> CreateEffectVarInput(const std::string & settingsID) const override;

private:
	template<class EffectType, class Effect>
	void EffectsFactory::RegisterEffectT(const std::string & settingsID)
	{
		if(std::is_same<EffectType, IEffectOneInput>())
		{
			if(m_creators.OneInput.find(settingsID) != m_creators.OneInput.cend())
				m_creators.OneInput[settingsID] = std::make_unique<EffectOneInputCreator<Effect>>();
		}
		else if(std::is_same<EffectType, IEffectTwoInput>())
		{
			if(m_creators.TwoInput.find(settingsID) != m_creators.TwoInput.cend())
				m_creators.TwoInput[settingsID] = std::make_unique<EffectTwoInputCreator<Effect>>();
		}
		else if(std::is_same<EffectType, IEffectVarInput>())
		{
			if(m_creators.VarInput.find(settingsID) != m_creators.VarInput.cend())
				m_creators.VarInput[settingsID] = std::make_unique<EffectVarInputCreator<Effect>>();
		}
		else
		{
			assert(!"EffectFacotry: Error on register effect!");
		}
	}

private:
	EffectsFactory();
	~EffectsFactory() = default;
	EffectsFactory(const EffectsFactory&) = delete;
	EffectsFactory& operator=(const EffectsFactory&) = delete;

private:
	EffectCreators m_creators;
};

}
