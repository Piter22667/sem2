#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "configurablewidget.h"
#include "toptestwidget.h"
#include "twobuttonswidget.h"
#include "testwindowmodel.h"


#include <QDialog>
#include <QFormLayout>
#include <QVector>



class TestWindow : public QDialog, public ConfigurableWidget
{
    Q_OBJECT

    TopTestWidget* topWidget;
    TwoButtonsWidget* buttonsWidget;
    TestWindowModel* model;

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow(){}
    void setModel(TestWindowModel* model);
signals:


    // ConfigurableWidget interface



private slots:
    void onDataUpdated(DataUpdatedIvent ivent);
    void onNextButtonClicked();
    void onPreviousButtonClicked();

private:
    void configureLayaut() override;
    void addWidgets() override;
    void configureWidgets() override;
    void connectWidgets() override;


    // ConfigurableWidget interface
protected:
    void updateUi() override;
};



#endif // TESTWINDOW_H
