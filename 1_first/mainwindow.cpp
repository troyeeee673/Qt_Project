#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , i(4)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "执行了MainWindow构造函数" << Qt::endl;
    school = new School(this);
    student = new Student(this);

    connect(school, SIGNAL(sendMessages()), student, SLOT(comeBackToClass()));
    emit school->sendMessages();//发送信号，触发comebBackToClass()

}

MainWindow::~MainWindow()
{
    qDebug() << "执行了MainWindow析构函数" << Qt::endl;
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    qDebug() << "按钮被点击" << Qt::endl;
}

