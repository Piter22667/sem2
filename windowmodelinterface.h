#ifndef WINDOWMODELINTERFACE_H
#define WINDOWMODELINTERFACE_H

#include <QObject>

struct DataUpdatedIvent
{
    enum EventType{
        testReceived,
        testSended,
        testListReceived,
        nextQuestion,
        testChecked

    };
    EventType type;
//    template<typename T>
//    T type(T t)
//    {
//        return t;
//    }
};

class WindowModelInterface : public QObject
{
    Q_OBJECT
public:

    explicit WindowModelInterface(QObject *parent = nullptr);

signals:
    void dataUpdatedWith(DataUpdatedIvent ivent);
};

#endif // WINDOWMODELINTERFACE_H
