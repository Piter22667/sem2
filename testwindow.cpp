#include "testwindow.h"

#include <QMessageBox>

TestWindow::TestWindow( QWidget *parent)
    : QDialog{parent}

{
    // model->updateDataSource();
}

void TestWindow::setModel(TestWindowModel *model)
{

    this->model = model;
    configure();
    connect(model,&TestWindowModel::dataUpdatedWith, this, onDataUpdated);
    topWidget->updateUi();

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
    case DataUpdatedIvent::testChecked:
        QMessageBox messageBox;
        messageBox.setWindowTitle("Результат тесту:                    ");
        messageBox.setText(model->getCheckedResult());
        messageBox.exec();
        break;

    }
}



void TestWindow::onPreviousButtonClicked()
{
    model->previousButtonClicked();
}

void TestWindow::onRadioButtonClicked(int id)
{
    model->onRadioButtonClicked(id);
}

void TestWindow::onNextButtonClicked()
{
    int id = 1;//Номер вибраної відповіді!!
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
    connect(buttonsWidget, &TwoButtonsWidget::firstButtonClicked, this, &TestWindow::onPreviousButtonClicked);
    connect(buttonsWidget, &TwoButtonsWidget::secondButtonClicked, this, &TestWindow::onNextButtonClicked);
    connect(topWidget, &TopTestWidget::radioButtonClicked, this, &TestWindow::onRadioButtonClicked);
}

void TestWindow::updateUi()
{
    topWidget->updateUi();
    buttonsWidget->updateUi();
}
