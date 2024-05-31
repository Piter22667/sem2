#ifndef TESTWINDOWMODEL_H
#define TESTWINDOWMODEL_H

//#include <QObject>
#include "windowmodelinterface.h"
#include "twobuttonsmodelinterface.h"
#include "testmodel.h"
#include "testresultmodel.h"

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
    void setName(QString name);


    QString getFirstButtonTitle() override;
    QString getSecondButtonTitle() override;

    void onRadioButtonClicked(int id);


    QString getCheckedResult() const;

    void setTrainTest(bool newTrainTest);

    bool getTrainTest() const;

signals:

private slots:

private:
    TestModel* test = nullptr;
    int currentQuestion;
    QVector<int> chosenAnswers;
    TestResultModel testResult;
    bool trainTest = true;

    void sendTestResult();
};

#endif // TESTWINDOWMODEL_H
