#include "mainwindowmodel.h"

TestsTableViewModel *MainWindowModel::getTestsTableModel()
{
    return testsTableModel;
}

MainWindowModel::MainWindowModel(QObject *parent)
    : WindowModelInterface{parent}
{
    testsTableModel = new TestsTableViewModel(tests, parent);

}

QString MainWindowModel::getFirstButtonTitle()
{
    return "Test";
}

QString MainWindowModel::getSecondButtonTitle()
{
    return "Pass";
}

void MainWindowModel::onDataReceived()
{
    DataUpdatedIvent event;
    event.type = DataUpdatedIvent::EventType::testListReceived;
    emit dataUpdatedWith(event);
}

void MainWindowModel::getDataSource()
{
    TestModel* test = new TestModel;
    test->name = "First test";
    Question question;
    question.questionText = "New question 1:";
    question.answers.push_back("Answer 1");
    question.answers.push_back("Answer 2");
    question.answers.push_back("Answer 3");
    question.correctAnswer = 2;
    test->questions.push_back(question);
    tests.push_back(test);

    onDataReceived();
}
