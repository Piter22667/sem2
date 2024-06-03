# Patterns(Lab2)

## **Singleton**

```cpp
class NetworkManager : public QObject
{
    Q_OBJECT

    QNetworkAccessManager *networkManager;
    const QString baseUrlString = "https://test1-cad1d-default-rtdb.firebaseio.com";

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
        QNetworkRequest request = QNetworkRequest(QUrl(baseUrlString + urlString));
        connect(networkManager, &QNetworkAccessManager::finished, this, &NetworkManager::requestFinished);
        networkManager->get(request);
    }

    void postRequest(QString urlString, QJsonObject data){
        QUrl url(baseUrlString + urlString);
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QJsonDocument jsonDoc(data);
        QByteArray jsonData = jsonDoc.toJson();
        networkManager->post(request, jsonData);
    }
```

Паттерн Singleton використовується у цьому класі NetworkManager для того, щоб забезпечити, що існує тільки один екземпляр цього класу в програмі. Це реалізовано за допомогою статичної змінної `instance`, яка ініціалізується при першому виклику методу `instance()`. Після цього всі наступні виклики `instance()` повертають той самий екземпляр класу. Це корисно, коли потрібно, щоб всі частини програми використовували один і той самий об'єкт, наприклад, для управління мережевими запитами.

Надалі при зверненні до екземпляру класу, завжди буде звернення до єдиного екземпляру:

```cpp
NetworkManager::instance()
```

```cpp
void MainWindowModel::getDataSource()
{
    NetworkManager::instance()->getRequest("/tests.json");
}

void TestWindowModel::sendTestResult()
{
    if (testResult.results.isEmpty()) {
        return;
    }

    // QJsonObject data;
    // data["data"] = testResult.toJson();
    **NetworkManager::instance()->postRequest**("/test_results/" + testResult.name + "/results.json", testResult.toJson());
}
//та при конекті сигналу зі слотом 

MainWindowModel::MainWindowModel(QObject *parent)
    : WindowModelInterface{parent}
{
    testsTableModel = new TestsTableViewModel(this);
    connect(**NetworkManager::instance()**, &NetworkManager::replyReceived, this, &MainWindowModel::onDataReceived);

}
```

## **Factory pattern**

```cpp
class **WindowsFactory**
{
public:
    enum class WindowType {
        Main,
        TestsAnswer,
        TrainTest,
        PassTest
    };

    static QWidget* createWindow(WindowType type) {
        switch (type) {
        case WindowType::Main:
            return new MainWindow();
        case WindowType::TestsAnswer:
            return new QMainWindow();
        case WindowsFactory::WindowType::TrainTest:
            return new TestWindow();
//        case WindowsFactory::WindowType::PassTest:
//            return new PassTestWindow();
        default:
            return nullptr;
        }

    }
};
```

Він дозволяє створювати об’єкти з різним типом посилаючись на єдиний шаблон створення.

Для створення вікна бажаного типу, викликається функція з відповідним вікном.

```cpp
**QWidget* mainWindow = WindowsFactory**::**createWindow**(WindowsFactory::WindowType::Main);
```

Кожне вікно заповнюється відповідними віджетами, які також змінені відповідно до класу.

## **Template pattern**

 

```cpp
**class ConfigurableWidget**
{
    //Composite
    //Template method
public:

    void **configure**()
    {
        configureLayaut();
        addWidgets();
        configureWidgets();
        connectWidgets();
    }

protected:
    **QLayout* mainLayout**;

    virtual void configureLayaut() = 0;
    virtual void addWidgets() = 0;
    virtual void configureWidgets() = 0;
    virtual void connectWidgets() = 0;
    virtual void updateUi() = 0;
};

```

кожен віртуальний метод реалізований у відповідних підкласах по-різному. Додається відповідний леяут, кнопки та віджети для зручної роботи з ними надалі.

## **Composite pattern**

```cpp
protected:
    QLayout* mainLayout;
```

mainLayout спочатку створюється як основний Layout для кожного вікна, а потім зі створеної ієрархії віджетів, він заповнюється відповідними віджетами

```cpp
void TopMainWindowWidget::configureLayaut() {
    **mainLayout = new QVBoxLayout;**

}

void TopMainWindowWidget::addWidgets() {
    tableView = new QTableView;
    tableView->verticalHeader()->setVisible(false);
    textBrowser = new QTextBrowser;
    **mainLayout->addWidget(tableView);
    mainLayout->addWidget(textBrowser);**
    setLayout(mainLayout);
}
```

У методі **`addWidgets`** створюються віджети (**`QTableView`**, **`QTextBrowser`**) і додаються у **`QVBoxLayout`** у класах **`MainWindow`** і **`TopMainWindowWidget`**.

В класі **`MainWindow`** встановлюється **`QVBoxLayout`** як головний макет центрального віджету вікна за допомогою **`setCentralWidget`**.