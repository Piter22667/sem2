#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QDebug>
// #include <QNetworkAccessManager>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>


class NetworkManager : public QObject
{
    Q_OBJECT

    QNetworkAccessManager *networkManager;
    const QString baseUrlString = "https://test1-cad1d-default-rtdb.firebaseio.com/tests.json";

    explicit NetworkManager(QObject *parent = nullptr) : QObject(parent){
        networkManager = new QNetworkAccessManager(this);
    }

    // QNetworkReply *reply;

public:    
    static NetworkManager* instance()
    {
        static NetworkManager instance;
        return &instance;
    }//singleton



    void getRequest(QString urlString){
        QNetworkRequest request = QNetworkRequest(QUrl(baseUrlString ));
        connect(networkManager, &QNetworkAccessManager::finished, this, &NetworkManager::requestFinished);
        networkManager->get(request);
    }
    void postRequest(QString urlString){


    }



signals:
    void replyReceived(QJsonDocument reply);

private slots:
    void requestFinished(QNetworkReply* reply){
        if (reply->error() == QNetworkReply::NoError) {
            // Отримання відповіді від сервера
            QByteArray responseData = reply->readAll();
            // Виведення вмісту відповіді
            qDebug() << "Response:" << responseData;
            emit replyReceived(QJsonDocument::fromJson(responseData));
        } else {
            // Виведення повідомлення про помилку
            qDebug() << "Error:" << reply->errorString();
        }



        reply->deleteLater();// Завершення обробки відповіді

    }


};

#endif // NETWORKMANAGER_H
