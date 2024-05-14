#ifndef TOPMAINWINDOWWIDGET_H
#define TOPMAINWINDOWWIDGET_H

#include "configurablewidget.h"
#include "mainwindowmodel.h"

#include <QTableView>
#include <QTextBrowser>
#include <QWidget>

class TopMainWindowWidget : public QWidget, public ConfigurableWidget
{
    Q_OBJECT
    MainWindowModel &model;
public:
    explicit TopMainWindowWidget(MainWindowModel &model, QWidget *parent = nullptr);

signals:
    void tableViewDoubleClicked(const QModelIndex &index);
    void tableViewClicked(const QModelIndex &index);


    // ConfigurableWidget interface
private:
    QTableView* tableView;
    QTextBrowser* textBrowser;
    void configureLayaut() override;
    void addWidgets() override;
    void configureWidgets() override;
    void connectWidgets() override;
private slots:
     void onTableViewDoubleClicked(const QModelIndex &index);
     void onTableViewClicked(const QModelIndex &index);


    // ConfigurableWidget interface
protected:
    void updateUi() override;
};

#endif // TOPMAINWINDOWWIDGET_H
