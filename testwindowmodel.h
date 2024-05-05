#ifndef TESTWINDOWMODEL_H
#define TESTWINDOWMODEL_H

//#include <QObject>
#include "windowmodelinterface.h"
#include "twobuttonsmodelinterface.h"
#include "testmodel.h"
#include <QVector>

class TestWindowModel : public WindowModelInterface, public TwoButtonsModelInterface
{
    Q_OBJECT
public:
    explicit TestWindowModel(QObject *parent = nullptr);

    QString getQuestion();
    QStringList getAnswers();

    void updateDataSource();

    void nextButtonClicked(int id);
    void previousButtonClicked();

    QString getFirstButtonTitle() override;
    QString getSecondButtonTitle() override;

signals:

private:
    TestModel* test = nullptr;
    int currentQuestion;
    QVector<int> chosenAnswers;
};

#endif // TESTWINDOWMODEL_H
