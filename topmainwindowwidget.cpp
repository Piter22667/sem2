#include "topmainwindowwidget.h"

TopMainWindowWidget::TopMainWindowWidget(QWidget *parent)
    : QWidget{parent}
{configure();}

void TopMainWindowWidget::configureLayaut() {
    mainLayout = new QVBoxLayout;

}

void TopMainWindowWidget::addWidgets() {
    tableView = new QTableView;
    textBrowser = new QTextBrowser;
    mainLayout->addWidget(tableView);
    mainLayout->addWidget(textBrowser);
    setLayout(mainLayout);

}

void TopMainWindowWidget::configureWidgets() {}

void TopMainWindowWidget::connectWidgets() {

    connect(tableView, &QTableView::doubleClicked, this, &TopMainWindowWidget::onTableViewDoubleClicked);
}

void TopMainWindowWidget::onTableViewDoubleClicked(const QModelIndex &index)
{
    emit tableViewDoubleClicked(index);
}

void TopMainWindowWidget::updateUi()
{

}
