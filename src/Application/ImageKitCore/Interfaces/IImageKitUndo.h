#pragma once

namespace ImageKitCore { namespace Interfaces {

class IImageKitUndo
{
public:
	virtual ~IImageKitUndo() = default;

	virtual void Push() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual void Reset() = 0;
};

}}
