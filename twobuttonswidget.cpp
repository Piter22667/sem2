#include "twobuttonswidget.h"
#include "mainwindow.h"


TwoButtonsWidget::TwoButtonsWidget(TwoButtonsModelInterface& model, QWidget *parent)
    : QWidget{parent},
    model(model)

{configure();}



void TwoButtonsWidget::configureLayaut() {
    mainLayout = new QHBoxLayout;

}

void TwoButtonsWidget::addWidgets() {
        firstButton = new QPushButton(model.getFirstButtonTitle());
        secondButton = new QPushButton(model.getSecondButtonTitle());
        mainLayout->addWidget(firstButton);
        mainLayout->addWidget(secondButton);
//        QWidget * centralWidget = new QWidget;
        setLayout(mainLayout);
//        setCentralWidget(centralWidget);

}

void TwoButtonsWidget::configureWidgets() {

}

void TwoButtonsWidget::connectWidgets() {
        connect(firstButton, &QPushButton::clicked, this, [&](){emit firstButtonClicked();});
        connect(secondButton, &QPushButton::clicked,  this, [&](){emit secondButtonClicked();});

}

void TwoButtonsWidget::updateUi()
{
    secondButton->setText(model.getSecondButtonTitle());

}
