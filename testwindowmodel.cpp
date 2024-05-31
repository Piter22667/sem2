#include "testwindowmodel.h"
#include <QDebug>

#include "networkmanager.h"

TestWindowModel::TestWindowModel(TestModel* test, QObject *parent)
    : WindowModelInterface{parent},
    currentQuestion{0}
{
    this->test = test;
    if (test != nullptr) {
        chosenAnswers.resize(test->questions.size());
        for(auto &answer:chosenAnswers){
            answer = 0;
        }
    }
}

QString TestWindowModel::getQuestion()
{
    if(test != nullptr && currentQuestion < test->questions.size()){
        return test->questions.at(currentQuestion).questionText;
    }
    return "";
}

QStringList TestWindowModel::getAnswers()
{
    if (test != nullptr && currentQuestion < test->questions.size()) {
        return test->questions.at(currentQuestion).answers;
    }
    return QStringList();
}

void TestWindowModel::nextButtonClicked(int id)
{
    if (test == nullptr || test->questions.isEmpty()) {
        return;
    }

    auto event = DataUpdatedIvent();
    if(currentQuestion < test->questions.size() - 1){
        currentQuestion++;
        event.type = DataUpdatedIvent::nextQuestion;
    } else {
        processingAnswers();
        event.type = DataUpdatedIvent::testChecked;
    }
    emit dataUpdatedWith(event);
    qDebug() << "Next";
}

void TestWindowModel::previousButtonClicked()
{
    if(currentQuestion > 0){
        currentQuestion--;
        auto event = DataUpdatedIvent();
        event.type = DataUpdatedIvent::nextQuestion;
        emit dataUpdatedWith(event);
    }
}

void TestWindowModel::processingAnswers()
{
    if (test == nullptr) {
        return;
    }

    int testNumber = testResult.results.size();
    testResult.results.append(TestResultModel::Result());
    testResult.results[testNumber].result = 0;
    testResult.results[testNumber].name = test->name;
    for(int i = 0; i < chosenAnswers.size(); i++){
        if(i < test->questions.size() && chosenAnswers[i] == test->questions[i].correctAnswer){
            testResult.results[testNumber].result++;
            qDebug() << chosenAnswers[i] << " " << test->questions[i].correctAnswer;
        }
    }
    if(!trainTest){
        sendTestResult();
    }
}

int TestWindowModel::getCurrentAnswerNumber()
{
    if (currentQuestion < chosenAnswers.size()) {
        return chosenAnswers.at(currentQuestion);
    }
    return -1;
}

void TestWindowModel::setName(QString name)
{
    testResult.name = name;

}

QString TestWindowModel::getFirstButtonTitle()
{
    return "Previous";
}

QString TestWindowModel::getSecondButtonTitle()
{
    if(test != nullptr && currentQuestion == test->questions.size() - 1){
        return "Send";
    }
    return "Next";
}

void TestWindowModel::onRadioButtonClicked(int id)
{
    if (currentQuestion < chosenAnswers.size()) {
        chosenAnswers[currentQuestion] = id;
        qDebug() << "Clicked: " << id;
    }
}

QString TestWindowModel::getCheckedResult() const
{
    if (test == nullptr) {
        return "";
    }

    int testNumber = testResult.results.size() - 1;
    if (testNumber >= 0 && testNumber < testResult.results.size()) {
        if (testResult.results[testNumber].result < test->minTestScore) {
            return "Тест не пройдено. Ваш бал: " + QString::number(testResult.results[testNumber].result);
        }
        return "Тест пройдено. Ваш бал: " + QString::number(testResult.results[testNumber].result);
    }

    return "";
}

void TestWindowModel::setTrainTest(bool newTrainTest)
{
    trainTest = newTrainTest;
}

bool TestWindowModel::getTrainTest() const
{
    return trainTest;
}

void TestWindowModel::sendTestResult()
{
    if (testResult.results.isEmpty()) {
        return;
    }

    // QJsonObject data;
    // data["data"] = testResult.toJson();
    NetworkManager::instance()->postRequest("/test_results/" + testResult.name + "/results.json", testResult.toJson());
}
