#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "windowmodelinterface.h"
#include "twobuttonsmodelinterface.h"
#include "teststableviewmodel.h"

#include <QNetworkReply>
class MainWindowModel : public WindowModelInterface, public TwoButtonsModelInterface
{
    Q_OBJECT
    QVector<TestModel*> tests;
    TestsTableViewModel* testsTableModel;

public:
    explicit MainWindowModel(QObject *parent = nullptr);

signals:


    // TwoButtonsModelInterface interface
public:
    QString getFirstButtonTitle() override;
    QString getSecondButtonTitle() override;
    void getDataSource();


    TestModel* getTest();


    TestsTableViewModel* getTestsTableModel();

    int getSelectedTestNumber() const;
    void setSelectedTestNumber(int newSelectedTestNumber);

private slots:
    void onDataReceived(const QJsonDocument &reply);


private:
    int selectedTestNumber = 0;
    void parseTests(const QJsonDocument &reply);
};



#endif // MAINWINDOWMODEL_H
