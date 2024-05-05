#include "testwindowmodel.h"
#include <QDebug>


TestWindowModel::TestWindowModel(QObject *parent)
    : WindowModelInterface{parent},
    currentQuestion{0}
{

}

QString TestWindowModel::getQuestion()
{
    if(test != nullptr){
        if(currentQuestion < test->questions.size()){
            return test->questions.at(currentQuestion).questionText;
        }
    }
    return "";
}

QStringList TestWindowModel::getAnswers()
{
    // QStringList answersList;
    // for(int i=0; i<4; i++ ){
    //     answersList.push_back(QString( "Answer: %1").arg(i));
    // }
    return test->questions.at(currentQuestion).answers;
}

void TestWindowModel::updateDataSource()
{
    test = new TestModel;
    test->testName = "First test";
    Question question;
    question.questionText = "New question 1:";
    question.answers.push_back("Answer 1");
    question.answers.push_back("Answer 2");
    question.answers.push_back("Answer 3");
    question.correctAnswer = 2;
    test->questions.push_back(question);

    Question question2;
    question2.questionText = "New question 2:";
    question2.answers.push_back("new Answer 1");
    question2.answers.push_back("new Answer 2");
    question2.answers.push_back("new Answer 3");
    question2.correctAnswer = 2;
    test->questions.push_back(question2);

    \
    for(int i = 0; i< test->questions.size(); i++){
     chosenAnswers.push_back(-1);
    }
}

void TestWindowModel::nextButtonClicked(int id)
{
    chosenAnswers[currentQuestion] = id;
    if(currentQuestion < test->questions.size() - 1){
        currentQuestion++;
    }
    auto event = DataUpdatedIvent();
    event.type = DataUpdatedIvent::nextQuestion;
    emit dataUpdatedWith(event);
    // qDebug() << "Next";
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

QString TestWindowModel::getFirstButtonTitle()
{
    return "Previous";
}

QString TestWindowModel::getSecondButtonTitle()
{
    if(currentQuestion == test->questions.size() - 1){
        return "Send";
    }
    return "Next";
}
