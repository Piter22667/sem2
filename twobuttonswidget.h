#ifndef TWOBUTTONSWIDGET_H
#define TWOBUTTONSWIDGET_H
#include "testwindowmodel.h"
#include "configurablewidget.h"

#include <QWidget>
#include <QPushButton>





class TwoButtonsWidget : public QWidget, public ConfigurableWidget
{
    Q_OBJECT
public:
    explicit TwoButtonsWidget(TwoButtonsModelInterface& model, QWidget *parent = nullptr);

signals:
    void firstButtonClicked();
    void secondButtonClicked();

    // ConfigurableWidget interface
private:
    void configureLayaut() override;
    void addWidgets() override;
    void configureWidgets() override;
    void connectWidgets() override;

    // ui widgets
    QPushButton* firstButton;
    QPushButton* secondButton;
    TwoButtonsModelInterface& model;


    // ConfigurableWidget interface
public:
    void updateUi() override;
};

#endif // TWOBUTTONSWIDGET_H
