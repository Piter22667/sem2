#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot/qcustomplot.h"
#include <QtCharts/QChartView>
#include "weatherservice.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct FuncParam{
    FuncParam(QString name, double minA, double maxA, double stepA, double minB, double maxB, double stepB, int maxX = 50, int minX = -50, int maxY = 50, int minY = -50, double stepX = 1):
        name{name},
        minA{minA},
        maxA{maxA},
        stepA{stepA},


        minB{minB},
        maxB{maxB},
        stepB{stepB},

        maxX{maxX},
        minX{minX},

        maxY{maxY},
        minY{minY},

        stepX{stepX}
    {
    }
    QString name;
    double minA;
    double minB;

    double maxA;
    double maxB;

    double stepA;
    double stepB;

    int maxX;
    int minX;
    int maxY;
    int minY;

    double stepX;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

     int maxX = 50;
     int minX = -50;
     int maxY = 5;
     int minY = -5;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QCustomPlot* plot;
    QPointer<QCPGraph> graph;
    QCustomPlot *customPlot;
    int functionType = 0;
    QVector<FuncParam> functions;
    QChartView* graphicsView;
    int columnCount = 0;
    WeatherService* weatherservice;


    void graphplot();
    double calculateY(double x);
    void initFunctions();
    void setupAxis();
    void setupCoefficientRanges();
    void setupTable();
    void setupDiagram();
    void setupWeather();

private slots:
    void onSliderChanged();
    void onMeteoDataReceived(QList<MeteoData> data);

    void on_comboBox_currentIndexChanged(int index);
    void onDiagramComboBoxCurrentIndexChanged(int index);

    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_addRowPushButton_clicked();
    void on_createDiagramPushButton_clicked();
    void on_spinBox_2_valueChanged(int arg1);
};
#endif // MAINWINDOW_H
