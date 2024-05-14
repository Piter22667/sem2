#include "mainwindow.h"
#include "windowsfactory.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    model{new MainWindowModel}
{
    configure();//template method
    model->getDataSource();
}

MainWindow::~MainWindow() {}

void MainWindow::onTrainButtonClicked()
{
    qDebug()<< "Test";
    auto window = dynamic_cast <TestWindow*> (WindowsFactory::createWindow(WindowsFactory::WindowType::TrainTest));
    auto *testWindowModel = new TestWindowModel(model->getTest());
    window->setModel(testWindowModel);
    window->exec();
}

void MainWindow::onPassButtonClicked()
{
    qDebug()<< "Pass";

}

void MainWindow::configureLayaut()
{
    mainLayout = new QVBoxLayout;
}

void MainWindow::addWidgets()
{
//    mainTableView = new QTableView;
//    trainTestButton = new QPushButton("Train test");
//    passTestButton = new QPushButton("Pass test");
    topwidget = new TopMainWindowWidget(*model);
    bottomWidget = new TwoButtonsWidget(*model);
    mainLayout->addWidget(topwidget);
    mainLayout->addWidget(bottomWidget);
    QWidget * centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}

void MainWindow::configureWidgets()
{
    resize(800, 600);
}

void MainWindow::connectWidgets()
{
    connect(topwidget, &TopMainWindowWidget::tableViewDoubleClicked, this, &MainWindow::onMainTableViewDoubleClicked);
    connect(topwidget, &TopMainWindowWidget::tableViewClicked, this, &MainWindow::onMainTableViewClicked);



    connect(bottomWidget, &TwoButtonsWidget::firstButtonClicked, this,&MainWindow::onTrainButtonClicked);
    connect(bottomWidget, &TwoButtonsWidget::secondButtonClicked, this,&MainWindow::onPassButtonClicked );
    connect(model, &MainWindowModel::dataUpdatedWith, this, &MainWindow::updateUi);
}

void MainWindow::onMainTableViewDoubleClicked(const QModelIndex &index)
{
    qDebug() << "Clicked on " << index.row();
}

void MainWindow::onMainTableViewClicked(const QModelIndex &index)
{
    model->setSelectedTestNumber(index.row());
}

void MainWindow::updateUi()
{

}
