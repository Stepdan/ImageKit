#pragma once

#include <deque>
#include <stack>

#include "UndoItem.h"

namespace ImageKitCore {

class UndoManager
{
public:
	UndoManager(const std::weak_ptr<IDataImage> & image, const std::string & tempPath);

	void Add(const std::weak_ptr<IDataImage> & image);
	UndoItem Undo();
	UndoItem Redo();
	UndoItem Reset();

private:
	std::string m_tempPath;
	int m_curIndex;

	std::deque<UndoItem> m_undoStack;
	std::stack<UndoItem> m_redoStack;
};

}
