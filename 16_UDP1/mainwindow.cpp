#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);

    // 接收消息
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray tmpByteArray;
        tmpByteArray.resize(udpSocket->pendingDatagramSize());

        QHostAddress ipaddr_sender;
        quint16 port_sender;

        udpSocket->readDatagram(tmpByteArray.data(), tmpByteArray.size(),
                                &ipaddr_sender, &port_sender);

        ui->textBrowser->append("收到来自 " + ipaddr_sender.toString() +
                                ":" + QString::number(port_sender) +
                                " → " + QString::fromUtf8(tmpByteArray));
    }
}

void MainWindow::on_pushButton_clicked()
{
    // 绑定 127.0.0.1:1901
    if (udpSocket->bind(QHostAddress::LocalHost, 1901)) {
        ui->textBrowser->append("成功绑定 127.0.0.1:1901");
    } else {
        ui->textBrowser->append("绑定失败: " + udpSocket->errorString());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    udpSocket->abort();
    ui->textBrowser->append("解除绑定");
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray data = ui->lineEdit->text().toUtf8();

    // 发送到 127.0.0.1:1901（和绑定地址一致）
    qint64 ret = udpSocket->writeDatagram(data, QHostAddress::LocalHost, 1901);

    if (ret == -1) {
        ui->textBrowser->append("发送失败: " + udpSocket->errorString());
    } else {
        ui->textBrowser->append("已发送: " + ui->lineEdit->text());
    }
}
//广播
void MainWindow::on_pushButton_4_clicked()
{
    QByteArray data = ui->lineEdit->text().toUtf8();

    // 广播地址：255.255.255.255
    qint64 ret = udpSocket->writeDatagram(data, QHostAddress::Broadcast, 1901);

    if (ret == -1) {
        ui->textBrowser->append("广播失败: " + udpSocket->errorString());
    } else {
        ui->textBrowser->append("已广播: " + ui->lineEdit->text());
    }
}

