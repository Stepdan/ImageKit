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
	~DataImageQt() = default;

public:
	const Types::ImageInfo & GetImageInfo() const noexcept override;
	uint8_t* GetData() override;
	std::shared_ptr<IDataImage> Copy(Types::CopyMode) const override;
};

}}
