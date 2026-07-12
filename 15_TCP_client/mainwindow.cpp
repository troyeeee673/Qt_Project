#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    this->setWindowTitle("客户端");
    //接收消息槽函数连接
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMassages()));
    //断开连接
    connect(tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(mstateChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveMassages()
{
    ui->textBrowser->append("服务端：" + tcpSocket->readAll());


}


void MainWindow::mstateChanged(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("断开连接");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textBrowser->append("已连接服务器");
        break;
    default:
        break;
    }
}





void MainWindow::on_pushButton_2_clicked()
{
    //与服务端建立连接
    tcpSocket->connectToHost("192.168.93.1", 1900);


}


void MainWindow::on_pushButton_3_clicked()
{
    tcpSocket->disconnectFromHost();
}


void MainWindow::on_pushButton_clicked()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write(ui->lineEdit->text().toUtf8());
    }
    else
        ui->textBrowser->append("未建立连接");

}

