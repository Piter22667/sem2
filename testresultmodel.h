#ifndef TESTRESULTMODEL_H
#define TESTRESULTMODEL_H

#include <QJsonArray>
#include <QJsonObject>

struct TestResultModel
{
    struct Result{
        QString name;
        int result;
        QJsonObject toJson(){
            QJsonObject json;
            json["name"] = name;
            json["result"] = result;
            return json;
        }
    };

    QString name;
    QVector<Result> results;

    TestResultModel();
    QJsonObject toJson(){
        QJsonObject json;
        // QJsonObject resultObject;
        QJsonArray resultsArray;
        for(auto &result:results){
            resultsArray.append(result.toJson());
        }
        json["results"] = resultsArray;
        // resultObject[name] = json;
        return results.first().toJson();
    }
};

#endif // TESTRESULTMODEL_H
