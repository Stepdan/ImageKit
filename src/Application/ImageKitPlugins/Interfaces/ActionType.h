#pragma once

namespace ImageKit {

enum class ActionType
{
	Default = 0,
	Undo,
	Redo,
	Reset,
    ApplyEffect,
	CancelEffect,
};

}
