#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "windowmodelinterface.h"
#include "twobuttonsmodelinterface.h"
class MainWindowModel : public WindowModelInterface, public TwoButtonsModelInterface
{
    Q_OBJECT
public:
    explicit MainWindowModel(QObject *parent = nullptr);

signals:


    // TwoButtonsModelInterface interface
public:
    QString getFirstButtonTitle() override;
    QString getSecondButtonTitle() override;
};


#endif // MAINWINDOWMODEL_H
