#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


struct MeteoData{
    QString date;
    double temperature;
};



class WeatherService : public QObject
{
    Q_OBJECT
public:
    explicit WeatherService(QObject *parent = nullptr);
    void perform(QString parametrs);
    virtual ~ WeatherService(){}


signals:
    void temeraturesReceived(QList<MeteoData> data);


private:
    QNetworkAccessManager manager;
    QString url = "https://api.open-meteo.com/v1/forecast";
    QNetworkReply* reply;

    void  proccessingResponse(QByteArray reply);


};

#endif // WEATHERSERVICE_H
