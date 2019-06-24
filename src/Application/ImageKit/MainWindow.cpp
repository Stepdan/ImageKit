#include "MainWindow.h"
#include "ui_MainWindow.h"

namespace ImageKit {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{

}

}
