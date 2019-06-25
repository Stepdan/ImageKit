#pragma once

#include <memory>

#include "src/Core/Interfaces/IDataImage.h"

using namespace Core::Interfaces;

namespace Core { namespace MediaTypes {

class DataImageQt : public IDataImage
{
public:
	static std::shared_ptr<IDataImage> Create();
	static std::shared_ptr<IDataImage> Create(const Types::ImageInfo &);

private:
	DataImageQt();
	DataImageQt(const DataImageQt & rhs);
	~DataImageQt();

public:
	const Types::ImageInfo & GetImageInfo() const noexcept override;
	uint8_t* GetData() override;
	const uint8_t* GetData() const override;
	std::shared_ptr<IDataImage> Copy(Types::CopyMode) const override;

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}}
