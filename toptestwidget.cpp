#include "toptestwidget.h"
#include <QFormLayout>

#include <QSplitter>
TopTestWidget::TopTestWidget(TestWindowModel& model ,QWidget *parent)
    : QWidget{parent},
      model{model}
{
    configure();
}


void TopTestWidget::configureLayaut()
{
    mainLayout = new QVBoxLayout;

}

void TopTestWidget::addWidgets()
{
    QFormLayout* formLayout = new QFormLayout(this);
    questionLabel = new QLabel(model.getQuestion());
    formLayout->addRow("Question: ", questionLabel);
    QStringList answers = model.getAnswers();
    for(int i=0; i < answers.size(); i++ ){
        auto button = new QRadioButton(this);
        radioButtons.push_back(button);
        auto label = new QLabel(answers.at(i) , this);
       labels.push_back(label);


        formLayout->addRow(button, label);
    }




//    mainLayout->addItem(formLayout);
//    mainLayout->addWidget(new QSplitter(Qt::Vertical, this));
//пусте місце між питаннями
}

void TopTestWidget::configureWidgets()
{

}

void TopTestWidget::connectWidgets()
{

}

void TopTestWidget::updateUi()
{
    questionLabel->setText(model.getQuestion());
    QStringList answers = model.getAnswers();
    for(int i=0; i < answers.size(); i++ ){
        radioButtons[i]->setChecked(false);
        labels[i]->setText(answers.at(i));
    }

}
