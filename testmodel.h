#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QString>
#include <QVector>

#include <QJsonObject>
#include <QJsonArray>

struct Question{
    QString questionText;
    QStringList answers;
    int correctAnswer;

    void fromJsonObject(const QJsonObject &jsonObj){
        questionText = jsonObj["question"].toString();
        correctAnswer = jsonObj["correct_answer"].toInt();

        QJsonArray answersArray = jsonObj["options"].toArray();
        for(const auto &answerValue:answersArray){
            QString answer = answerValue.toString();
            answers.append(answer);
        }

    }
};


struct TestModel
{
    QString name;
    QString id;
    int minTestScore;

    QString description;
    QVector<Question> questions;

    void fromJsonObject(const QJsonObject &jsonObj){
        name = jsonObj["name"].toString();
        id = jsonObj["id"].toString();
        minTestScore = jsonObj["min_test_score"].toInt();
        description = jsonObj["description"].toString();

        QJsonArray questionsArray = jsonObj["questions"].toArray();
        for(const auto &questionValue:questionsArray){
            QJsonObject questionObject = questionValue.toObject();
            Question question;
            question.fromJsonObject(questionObject);
            questions.append(question);
        }
    }
};

#endif // TESTMODEL_H
