#include "UndoManager.h"

namespace ImageKitCore {

UndoManager::UndoManager(const std::weak_ptr<IDataImage> & image, const std::string & tempPath)
    : m_tempPath(tempPath)
{
	Add(image);
};

//.............................................................................

void UndoManager::Add(const std::weak_ptr<IDataImage> & image)
{
	m_undoStack.emplace_back(image, m_tempPath, m_curIndex++);

	if(!m_redoStack.empty())
		std::stack<UndoItem>().swap(m_redoStack);
}

//.............................................................................

UndoItem UndoManager::Undo()
{
	if(m_undoStack.empty())
		return UndoItem();

	m_redoStack.push(m_undoStack.back());
	m_undoStack.pop_back();
}

//.............................................................................

UndoItem UndoManager::Redo()
{
	if(m_redoStack.empty())
		return m_undoStack.back();

	m_undoStack.push_back(m_redoStack.top());
	m_redoStack.pop();
}

//.............................................................................

UndoItem UndoManager::Reset()
{
	const auto & item = m_undoStack.front();
	m_undoStack.clear();
	std::stack<UndoItem>().swap(m_redoStack);
	m_undoStack.push_back(item);

	return item;
}

}
