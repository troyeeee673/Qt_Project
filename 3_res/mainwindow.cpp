#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //this->setStyleSheet("QWidget { background-color: blue}");
    QLabel *label = new QLabel(this);
    label->setGeometry(0, 0, 100, 100);
    QLabel *label2 = new QLabel(this);
    label2->setGeometry(100, 100, 100, 100);
    label2->setObjectName("label2");

    //label->setStyleSheet("QLabel { background-color: red}");
    this->resize(800, 480);
    // ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
