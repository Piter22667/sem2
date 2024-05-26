#include "testwindowmodel.h"
#include <QDebug>


TestWindowModel::TestWindowModel(TestModel* test, QObject *parent)
    : WindowModelInterface{parent},
    currentQuestion{0}
{
    this->test = test;
    chosenAnswers.resize(test->questions.size());
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

// void TestWindowModel::updateDataSource()
// {
//     test = new TestModel;
//     test->name = "First test";
//     Question question;
//     question.questionText = "New question 1:";
//     question.answers.push_back("Answer 1");
//     question.answers.push_back("Answer 2");
//     question.answers.push_back("Answer 3");
//     question.correctAnswer = 2;
//     test->questions.push_back(question);

//     Question question2;
//     question2.questionText = "New question 2:";
//     question2.answers.push_back("new Answer 1");
//     question2.answers.push_back("new Answer 2");
//     question2.answers.push_back("new Answer 3");
//     question2.correctAnswer = 2;
//     test->questions.push_back(question2);

//     \
//     for(int i = 0; i< test->questions.size(); i++){
//      chosenAnswers.push_back(-1);
//     }
// }

void TestWindowModel::nextButtonClicked(int id)
{
    auto event = DataUpdatedIvent();
    chosenAnswers[currentQuestion] = id;
    if(currentQuestion < test->questions.size() - 1){
        currentQuestion++;
        event.type = DataUpdatedIvent::nextQuestion;

    }
    else{
        processingAnswers();
        event.type = DataUpdatedIvent::testChecked;
    }
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

void TestWindowModel::processingAnswers()
{
    // checkedMark = 20;
    for(int i =0; i <= chosenAnswers.size(); i++){
        if(chosenAnswers[i] == test->questions[i].correctAnswer){
            checkedMark++;
        }
    }
}

int TestWindowModel::getCurrentAnswerNumber()
{
    return chosenAnswers.at(currentQuestion);
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

void TestWindowModel::onRadioButtonClicked(int id)
{
    chosenAnswers[currentQuestion] = id;

}

QString TestWindowModel::getCheckedResult() const
{
    if(checkedMark < test->minTestScore){
        return "Тест не пройдено. Ваш бал: " + QString::number(checkedMark) ;
    }

    return "Тест пройдено. Ваш бал: " + QString::number(checkedMark) ;
}
