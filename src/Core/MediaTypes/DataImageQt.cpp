#include <QImage>

#include "DataImageQt.h"

namespace Core::MediaTypes {

class DataImageQt::Impl
{
public:
	Impl();
	Impl(const QImage& image, Types::CopyMode mode)
	{
		if(mode == Types::CopyMode::Deep)
			m_image = image.copy();
		else
			m_image = image;
	}

	// Shallow copying
	Impl(const Impl& rhs) { m_image = rhs.m_image; }
	Impl& operator=(const Impl& rhs) { m_image = rhs.m_image; return *this; }

	Types::ImageInfo GetImageInfo() const
	{
		Types::ImageInfo info;
		info.Width = m_image.width();
		info.Height = m_image.height();
		return info;
	}

	uint8_t* GetData() { return m_image.bits(); }
	const uint8_t* GetData() const { return m_image.bits(); }

	std::unique_ptr<Impl> Copy(Types::CopyMode mode) const
	{
		return std::make_unique<Impl>(m_image, mode);
	}

private:
	QImage m_image;
};

//.............................................................................

std::shared_ptr<IDataImage> DataImageQt::Create()
{
	return std::make_shared<DataImageQt>();
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageQt::Create(const Types::ImageInfo & info)
{
	return std::make_shared<DataImageQt>(info);
}

//.............................................................................

DataImageQt::DataImageQt()
{}

//.............................................................................

DataImageQt::DataImageQt(const DataImageQt & rhs)
    : m_impl(new Impl(*rhs.m_impl.get()))
{}

//.............................................................................

DataImageQt::~DataImageQt() = default;

//.............................................................................

const Types::ImageInfo & DataImageQt::GetImageInfo() const noexcept
{
	return m_impl->GetImageInfo();
}

//.............................................................................

uint8_t* DataImageQt::GetData()
{
	return m_impl->GetData();
}

//.............................................................................

const uint8_t* DataImageQt::GetData() const
{
	return m_impl->GetData();
}

//.............................................................................

std::shared_ptr<IDataImage> DataImageQt::Copy(Types::CopyMode copyMode) const
{
	auto newImpl = m_impl->Copy(copyMode);
	auto newDataImageQt = std::make_shared<DataImageQt>();
	newDataImageQt->m_impl.swap(newImpl);

	return newDataImageQt;
}

}
