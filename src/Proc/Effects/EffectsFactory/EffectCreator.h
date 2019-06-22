#pragma once

#include <map>
#include <memory>

#include "src/Proc/Interfaces/IEffectCreator.h"

using namespace Proc::Interfaces;

namespace Proc {

template<class Effect>
class EffectOneInputCreator : public IEffectOneInputCreator
{
public:
	std::shared_ptr<IEffectOneInput> Create() const override
	{
		return std::make_shared<Effect>();
	}
};

template<class Effect>
class EffectTwoInputCreator : public IEffectTwoInputCreator
{
public:
	std::shared_ptr<IEffectTwoInput> Create() const override
	{
		return std::make_shared<Effect>();
	}
};

template<class Effect>
class EffectVarInputCreator : public IEffectVarInputCreator
{
public:
	std::shared_ptr<IEffectVarInput> Create() const override
	{
		return std::make_shared<Effect>();
	}
};

struct EffectCreators
{
public:
	std::map<std::string, std::unique_ptr<IEffectOneInputCreator>> OneInput;
	std::map<std::string, std::unique_ptr<IEffectTwoInputCreator>> TwoInput;
	std::map<std::string, std::unique_ptr<IEffectVarInputCreator>> VarInput;
};

}
