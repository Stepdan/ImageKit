#pragma once

#include <memory>

namespace Proc { namespace Interfaces {

class IEffectOneInput;
class IEffectTwoInput;
class IEffectVarInput;

class IEffectOneInputCreator
{
public:
	virtual ~IEffectOneInputCreator() = default;

	virtual std::shared_ptr<IEffectOneInput> Create() const = 0;
};

class IEffectTwoInputCreator
{
public:
	virtual ~IEffectTwoInputCreator() = default;

	virtual std::shared_ptr<IEffectTwoInput> Create() const = 0;
};

class IEffectVarInputCreator
{
public:
	virtual ~IEffectVarInputCreator() = default;

	virtual std::shared_ptr<IEffectVarInput> Create() const = 0;
};

}}
