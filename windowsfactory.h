#ifndef WINDOWSFACTORY_H
#define WINDOWSFACTORY_H
#include "mainwindow.h"
#include "testwindow.h"



class WindowsFactory
{
public:
    enum class WindowType {
        Main,
        TestsAnswer,
        TrainTest,
        PassTest
    };

    static QWidget* createWindow(WindowType type) {
        switch (type) {
        case WindowType::Main:
            return new MainWindow();
        case WindowType::TestsAnswer:
            return new QMainWindow();
        case WindowsFactory::WindowType::TrainTest:
            return new TestWindow();
//        case WindowsFactory::WindowType::PassTest:
//            return new PassTestWindow();
        default:
            return nullptr;
        }

    }
};

#endif // WINDOWSFACTORY_H
