#include <cassert>

#include "UndoManager.h"

namespace ImageKitCore {

UndoManager::UndoManager(const std::weak_ptr<IDataImage> & image, const std::string & tempPath)
    : m_tempPath(tempPath)
{
    Push(image);
};

//.............................................................................

void UndoManager::Push(const std::weak_ptr<IDataImage> & image)
{
    m_undoStack.emplace_back(image, m_tempPath, m_curIndex++);

    if(!m_redoStack.empty())
        std::stack<UndoItem>().swap(m_redoStack);
}

//.............................................................................

const UndoItem & UndoManager::Undo()
{
    if(m_undoStack.size() == 1)
        return m_undoStack.back();

    m_redoStack.push(m_undoStack.back());
    m_undoStack.pop_back();

    return m_undoStack.back();
}

//.............................................................................

const UndoItem & UndoManager::Redo()
{
    if(m_redoStack.empty())
        return m_undoStack.back();

    m_undoStack.push_back(m_redoStack.top());
    m_redoStack.pop();

    return m_undoStack.back();
}

//.............................................................................

const UndoItem & UndoManager::Reset()
{
    std::stack<UndoItem>().swap(m_redoStack);
    std::deque<UndoItem>({m_undoStack.front()}).swap(m_undoStack);

    return m_undoStack.back();
}

}
