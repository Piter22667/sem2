#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include <QTableView>
#include "configurablewidget.h"
#include "twobuttonswidget.h"
#include "topmainwindowwidget.h"
#include "mainwindowmodel.h"






class MainWindow : public QMainWindow, public ConfigurableWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onTrainButtonClicked();
    void onPassButtonClicked();

    // ConfigurableWidgetInterface interface
private:
    void configureLayaut() override;
    void addWidgets() override;
    void configureWidgets() override;
    void connectWidgets() override;

    //ui widgets
//    QTableView* mainTableView;
    TopMainWindowWidget* topwidget;
    TwoButtonsWidget* bottomWidget;
    MainWindowModel* model;

private slots:
    void onMainTableViewDoubleClicked(const QModelIndex &index);
    void onMainTableViewClicked(const QModelIndex &index);


    // ConfigurableWidget interface
protected:
    void updateUi() override;
};
#endif // MAINWINDOW_H
