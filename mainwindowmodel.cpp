#include "mainwindowmodel.h"
#include "networkmanager.h"

#include <QJsonDocument>

TestsTableViewModel* MainWindowModel::getTestsTableModel()
{
    return testsTableModel;
}

MainWindowModel::MainWindowModel(QObject *parent)
    : WindowModelInterface{parent}
{
    testsTableModel = new TestsTableViewModel(this);
    connect(NetworkManager::instance(), &NetworkManager::replyReceived, this, &MainWindowModel::onDataReceived);

}

QString MainWindowModel::getFirstButtonTitle()
{
    return "Test";
}

QString MainWindowModel::getSecondButtonTitle()
{
    return "Pass";
}

void MainWindowModel::onDataReceived(const QJsonDocument &reply)
{
    parseTests(reply);

    testsTableModel->testsDataUpdated(tests);
    DataUpdatedIvent event;
    event.type = DataUpdatedIvent::EventType::testListReceived;
    emit dataUpdatedWith(event);
}

void MainWindowModel::parseTests(const QJsonDocument &reply)
{
    if(reply.isNull()){
        qWarning("No tests avaliable");
    }

    if(reply.isArray()){
        auto testsJsonArray = reply.array();
        for(auto const &testJsonValue:testsJsonArray){
            auto testJsonObject = testJsonValue.toObject();

            TestModel* test = new TestModel;
            test->fromJsonObject(testJsonObject);
            tests.append(test);
        }
    }
}

int MainWindowModel::getSelectedTestNumber() const
{
    return selectedTestNumber;
}

void MainWindowModel::setSelectedTestNumber(int newSelectedTestNumber)
{
    selectedTestNumber = newSelectedTestNumber;
}

void MainWindowModel::getDataSource()
{
    NetworkManager::instance()->getRequest("/tests.json");

    // TestModel* test = new TestModel;
    // test->minTestScore = "60";
    // test->name = "First test";
    // Question question;
    // question.questionText = " Question 1:";
    // question.answers.push_back("Answer 1");
    // question.answers.push_back("Answer 2");
    // question.answers.push_back("Answer 3");
    // question.correctAnswer = 2;
    // test->questions.push_back(question);

    // Question question1;
    // question1.questionText = "New question 1:";
    // question1.answers.push_back(" New Answer 1");
    // question1.answers.push_back("New Answer 2");
    // question1.answers.push_back("Updated Answer 3");
    // question1.correctAnswer = 2;
    // test->questions.push_back(question1);
    // tests.push_back(test);

    // TestModel* secondTest = new TestModel;
    // secondTest->minTestScore = "60";
    // secondTest->name = "Second test";
    // Question question3;
    // question3.questionText = "2 Question :";
    // question3.answers.push_back("2 Answer ");
    // question3.answers.push_back("2 Answer ");
    // question3.answers.push_back("2 Answer ");
    // question.correctAnswer = 2;
    // secondTest->questions.push_back(question3);

    // tests.push_back(secondTest);
    // onDataReceived();
}

TestModel* MainWindowModel::getTest()
{
    return tests.at(selectedTestNumber);
}


