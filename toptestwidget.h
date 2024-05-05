#ifndef TOPTESTWIDGET_H
#define TOPTESTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include "configurablewidget.h"
#include "testwindowmodel.h"

class TopTestWidget : public QWidget, public ConfigurableWidget
{
    Q_OBJECT
public:
    explicit TopTestWidget(TestWindowModel& model ,QWidget *parent = nullptr);


signals:

private:
   QVector<QLabel*> labels;
    QVector<QRadioButton*> radioButtons;
    TestWindowModel& model;
    QLabel* questionLabel;

    // ConfigurableWidget interface
    void configureLayaut() override;
    void addWidgets() override;
    void configureWidgets() override;
    void connectWidgets() override;




    // ConfigurableWidget interface
public:
    void updateUi() override;
};

#endif // TOPTESTWIDGET_H
