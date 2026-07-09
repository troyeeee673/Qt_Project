#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "选择文件", "D:/ov_Watch/OV-Watch");
    qDebug() <<"filename:"<<filename<< Qt::endl;
    //设置要打开的文件
    file.setFileName(filename);
    //打开文件
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() <<"open file failed"<< Qt::endl;
        return ;
    }
    ui->textEdit->setPlainText(file.readAll());

    //关闭文件
    file.close();


}


void MainWindow::on_pushButton_2_clicked()
{
    if(file.fileName().isEmpty())
    {
        qDebug()<<"no file opening"<<Qt::endl;
        return;
    }
    file.open(QIODevice::ReadWrite);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
    ui->textEdit->clear();
}

