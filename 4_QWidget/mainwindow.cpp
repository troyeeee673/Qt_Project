#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setCheckable(true);//设置可选中属性， 这样才能使toggled信号生效
    ui->pushButton_2->setCheckable(true);//设置可选中属性， 这样才能使toggled信号生效
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "clicked"<< Qt::endl;

}


void MainWindow::on_pushButton_pressed()
{
    qDebug() << "pressed" << Qt::endl;
}


void MainWindow::on_pushButton_released()
{
    qDebug() << "released" << Qt::endl;
}


void MainWindow::on_pushButton_toggled(bool checked)
{
    qDebug() << "toggled" << checked << Qt::endl;
}

