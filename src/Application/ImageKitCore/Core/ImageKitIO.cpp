#include "ImageKitCore.h"

namespace ImageKitCore {

void ImageKitCore::Load(const std::string & path)
{
}

//.............................................................................

void ImageKitCore::Save(const std::string & path) const
{}

//.............................................................................

const std::string & ImageKitCore::GetSessionTempDir() const noexcept
{
	return m_tempDir;
}

}
