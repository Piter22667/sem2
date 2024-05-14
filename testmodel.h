#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QString>
#include <QVector>
struct Question{
    QString questionText;
    QStringList answers;
    int correctAnswer;
};


struct TestModel
{
    QString name;
    int id;
    QString minTestScore;

    QString description;
    QVector<Question> questions;
};

#endif // TESTMODEL_H
