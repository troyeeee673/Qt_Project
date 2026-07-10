#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QValueAxis>
#include <QSplineSeries>
#include <QLineSeries>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*1. 创建图标视图(这里注释，因为手动在ui中创建了)*/
    // QChartView *chartVirw = new QChartView();

    /*2. 创建图表（要放到图表视图中）*/
    QChart *chart = new QChart();

    /*3. 创建坐标轴*/
    QValueAxis *valueAxisx = new QValueAxis();
    QValueAxis *valueAxisy = new QValueAxis();

    /*4. 设置坐标轴范围*/
    valueAxisx->setRange(0, 5000);
    valueAxisy->setRange(0, 100);

    /*5. 设置坐标轴标题和显示格式*/
    valueAxisx->setTitleText("时间/ms");
    valueAxisy->setTitleText("温度/°C");
    valueAxisx->setLabelFormat("%d");
    valueAxisy->setLabelFormat("%d");

    /*6. 将坐标轴添加到图表中*/
    chart->createDefaultAxes();
    chart->addAxis(valueAxisx, Qt::AlignBottom);
    chart->addAxis(valueAxisy, Qt::AlignLeft);

    /*7. 设置图表标题和图例*/
    chart->setTitle("温度与时间曲线");
    chart->legend()->setVisible(false);

    /*8. 创建曲线对象，添加点*/
    QSplineSeries *splineSeries = new QSplineSeries();
    splineSeries->append(0, 50);
    splineSeries->append(1000, 60);
    splineSeries->append(2000, 80);
    splineSeries->append(3000, 50);
    splineSeries->append(4000, 30);
    splineSeries->append(5000, 80);

    QPen pen(QColor(0xff5566));
    splineSeries->setPen(pen);

    /*9. 图表添加曲线*/
    chart->addSeries(splineSeries);

    /*10. 将图表数据与坐标轴联系起来*/
    splineSeries->attachAxis(valueAxisx);
    splineSeries->attachAxis(valueAxisy);

    /*11 .将图表放到图标视图中进行显示*/
    ui->chartView->setChart(chart);













}

MainWindow::~MainWindow()
{
    delete ui;
}
