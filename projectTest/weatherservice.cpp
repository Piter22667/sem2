#include "weatherservice.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


WeatherService::WeatherService(QObject *parent)
    : QObject{parent}
{



}

void WeatherService::perform(QString parametrs)
{
    QNetworkRequest request(QUrl (url +  parametrs));
    reply = manager.get(request);
    connect(reply, &QNetworkReply::finished, this,  [&]() {
        if(reply->error() == QNetworkReply::NoError){
            QByteArray response = reply->readAll();
            qDebug() << "response:" << response;
            proccessingResponse(response);


        }
        else{
            qDebug() << "error:" << reply->errorString();
            }
    } );
}

void WeatherService::proccessingResponse(QByteArray reply)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(reply);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << jsonResponse;
    QJsonObject hourly = jsonObject["hourly"].toObject();
    QJsonArray jsonTimes = hourly["time"].toArray();
    QJsonArray jsonTemperatures = hourly["temperature_2m"].toArray();
    QList<MeteoData> data;
//    QList<QString> times;
//    QList<double> temperatures;
//    foreach(const QJsonValue& time, jsonTimes){
//        times.append(time.toString());
//    }

//    foreach(const QJsonValue& temperature, jsonTemperatures){
//        temperatures.append(temperature.toDouble());
//    }
    for(int i = 0; i< jsonTimes.count(); i++){
        data.append({jsonTimes[i].toString(), jsonTemperatures[i].toDouble()});
    }

//    MeteoData data = {times, temperatures};

    emit temeraturesReceived(data);
}

