#ifndef TESTWINDOWMODEL_H
#define TESTWINDOWMODEL_H

//#include <QObject>
#include "windowmodelinterface.h"
#include "twobuttonsmodelinterface.h"
#include "testmodel.h"

#include <QButtonGroup>

class TestWindowModel : public WindowModelInterface, public TwoButtonsModelInterface
{
    Q_OBJECT
public:
    explicit TestWindowModel(TestModel* test, QObject *parent = nullptr);

    QString getQuestion();
    QStringList getAnswers();

    void updateDataSource();

    void nextButtonClicked(int id);
    void previousButtonClicked();
    void processingAnswers();
    int getCurrentAnswerNumber();


    QString getFirstButtonTitle() override;
    QString getSecondButtonTitle() override;

    void onRadioButtonClicked(int id);


    QString getCheckedResult() const;

signals:

private slots:

private:
    TestModel* test = nullptr;
    int currentQuestion;
    QVector<int> chosenAnswers;
    int checkedMark = 0;

};

#endif // TESTWINDOWMODEL_H
