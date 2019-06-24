#pragma once

#include <QVariantMap>

#include "ActionType.h"

namespace ImageKit {

struct ImageKitAction
{
	ActionType Type;
	QVariantMap Params;
};

}
