#pragma once

#include <QApplication>

namespace ImageKit {

class Application : public QApplication
{
	Q_OBJECT

public:
	Application(int& argc, char** argv);

	void SetStyle();

};

}

#define imageKitApp (static_cast<ImageKit::Application*>(QApplication::instance()))
