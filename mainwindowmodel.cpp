#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel(QObject *parent)
    : WindowModelInterface{parent}
{

}

QString MainWindowModel::getFirstButtonTitle()
{
    return "Test";
}

QString MainWindowModel::getSecondButtonTitle()
{
    return "Pass";
}
