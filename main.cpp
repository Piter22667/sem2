#include "windowsfactory.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = (MainWindow *) WindowsFactory::createWindow(WindowsFactory::WindowType::Main);
    w->show();
    auto result = a.exec();
    delete w;
    return result;
}
