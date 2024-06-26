#include "topmainwindowwidget.h"
#include <QHeaderView>

TopMainWindowWidget::TopMainWindowWidget(MainWindowModel &model, QWidget *parent)
    : model(model)
    ,QWidget{parent}
{configure();}

void TopMainWindowWidget::configureLayaut() {
    mainLayout = new QVBoxLayout;

}

void TopMainWindowWidget::addWidgets() {
    tableView = new QTableView;
    tableView->verticalHeader()->setVisible(false);
    textBrowser = new QTextBrowser;
    mainLayout->addWidget(tableView);
    mainLayout->addWidget(textBrowser);
    setLayout(mainLayout);
}

void TopMainWindowWidget::configureWidgets() {
    tableView->setModel(model.getTestsTableModel());

}

void TopMainWindowWidget::connectWidgets() {

    connect(tableView, &QTableView::doubleClicked, this, &TopMainWindowWidget::onTableViewDoubleClicked);
    connect(tableView,&QTableView::clicked, this, &TopMainWindowWidget::onTableViewClicked);
}

void TopMainWindowWidget::onTableViewDoubleClicked(const QModelIndex &index)
{
    emit tableViewDoubleClicked(index);
}

void TopMainWindowWidget::onTableViewClicked(const QModelIndex &index)
{
    emit tableViewClicked(index);
}

void TopMainWindowWidget::updateUi()
{

}
