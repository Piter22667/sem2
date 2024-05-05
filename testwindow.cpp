#include "testwindow.h"

TestWindow::TestWindow(QWidget *parent)
    : QDialog{parent},
    model{new TestWindowModel(parent)}

{
    model->updateDataSource();
    configure();

}

void TestWindow::onDataUpdated(DataUpdatedIvent ivent)
{
    qDebug() << "Updated with " << ivent.type;
    switch(ivent.type){
    case DataUpdatedIvent::nextQuestion:
        topWidget->updateUi();
        buttonsWidget->updateUi();
        break;
    case DataUpdatedIvent::testReceived:
        topWidget->updateUi();
        break;
    case DataUpdatedIvent::testSended:
        break;
    case DataUpdatedIvent::testListReceived:
        break;

    }
}



void TestWindow::onPreviousButtonClicked()
{
    model->previousButtonClicked();
}

void TestWindow::onNextButtonClicked()
{
    int id = 1;
    model->nextButtonClicked(id);

}



void TestWindow::configureLayaut()
{
    mainLayout = new QVBoxLayout;

}

void TestWindow::addWidgets()
{
    topWidget= new TopTestWidget(*model);
    buttonsWidget = new TwoButtonsWidget(*model);

    mainLayout->addWidget(topWidget);
    mainLayout->addWidget(buttonsWidget);

//    QWidget * centralWidget = new QWidget;
    setLayout(mainLayout);
//    setCentralWidget(centralWidget);

}

void TestWindow::configureWidgets()
{
    resize(600, 500);

}

void TestWindow::connectWidgets()
{
    connect(model,&TestWindowModel::dataUpdatedWith, this, onDataUpdated);
    connect(buttonsWidget, &TwoButtonsWidget::firstButtonClicked, this, &TestWindow::onPreviousButtonClicked);
    connect(buttonsWidget, &TwoButtonsWidget::secondButtonClicked, this, &TestWindow::onNextButtonClicked);
}

void TestWindow::updateUi()
{
    topWidget->updateUi();
    buttonsWidget->updateUi();
}
