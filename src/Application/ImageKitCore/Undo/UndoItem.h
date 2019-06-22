#pragma once

#include <string>

#include "src/Core/Interfaces/IDataImage.h"

using namespace Core::Interfaces;

namespace ImageKitCore {

struct UndoItem
{
public:
	UndoItem() = default;
	UndoItem(const std::weak_ptr<IDataImage> & image, const std::string & tempPath, int index)
	    : Image(image), TempPath(tempPath), Index(index) {}

	bool IsEmpty() { return Index < 0; }

	std::weak_ptr<IDataImage> Image;
	std::string TempPath;
	int Index{-1};
};

}
