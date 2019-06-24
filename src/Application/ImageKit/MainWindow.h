#pragma once

#include <memory>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

namespace ImageKit {

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	std::unique_ptr<Ui::MainWindow> m_ui;
};

}
