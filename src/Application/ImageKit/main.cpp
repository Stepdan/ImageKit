#include "Application.h"
#include "Mediator.h"

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	ImageKit::Application application(argc, argv);

	std::shared_ptr<ImageKit::MainWindow> mainForm(new ImageKit::MainWindow());
	ImageKit::Mediator mediator(mainForm);

	imageKitApp->installEventFilter(&mediator);
	imageKitApp->installEventFilter(mainForm.get());

	//visionApp->SetStyle();

	mainForm->show();

	return application.exec();
}
