#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    this->setWindowTitle("服务端");
    //连接信号槽，发送方是服务端，当收到newConnection信号时，触发mNewConnection方法
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(mNewConnection()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mNewConnection()
{
    //与客户端连接。通过调用服务端的nextPendingConnection函数动态创建QTcpSocket对象
    QTcpSocket *temTcpSocket = tcpServer->nextPendingConnection();//这里会返回一个QTcpSocket对象，这个对象其实是tcpServer的子对象，当TcpServer销毁时，这些对象会自动被销毁，因此不需要手动delete
                                                                //但是为了避免浪费内存，也可以在使用完某个具体的连接后，手动释放
    //打印客户端的ip信息等
    ui->textBrowser->append("客户端ip地址：" + temTcpSocket->peerAddress().toString());
 ui->textBrowser->append("客户端port：" + QString::number(temTcpSocket->peerPort()));
    //当有新的数据到来时（触发readyRead信号），调用receiveMessages()函数
    connect(temTcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessages()));
    //当连接状态发送改变时，调用函数mstateChanged
    connect(temTcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(mstateChanged(QAbstractSocket::SocketState)));

}

void MainWindow::receiveMessages()
{
    //从发送方拿到QTcpSocket对象
    QTcpSocket *tmptcpSocket = (QTcpSocket *)sender();
    //从QTcpSocket对象中读取数据
    ui->textBrowser->append(tmptcpSocket->readAll());


}

void MainWindow::mstateChanged(QAbstractSocket::SocketState state)
{
    //从发出state改变信号的对象获得QTcpSocket对象，对其进行释放（连接使用完毕）
    QTcpSocket *tmpTcpSocket = (QTcpSocket *)sender();
    switch(state)
    {
        case QAbstractSocket::UnconnectedState:
        //向textBrowser中追加打印信息
            ui->textBrowser->append("客户端断开连接");
        //释放连接
            delete(tmpTcpSocket);
            break;
        case QAbstractSocket::ConnectedState:
            ui->textBrowser->append("客户端已连接");
            break;
        default:
            break;

    }

}

void MainWindow::on_pushButton_3_clicked()
{
    //这里使用list容器接收客户端的数据，因为可能有多个客户端
    QList<QTcpSocket*> socketList = tcpServer->findChildren<QTcpSocket *>();
    foreach(QTcpSocket *tmpTcpSocket, socketList)
    {
        //服务端向每个客户端发送消息
        tmpTcpSocket->write(ui->lineEdit->text().toUtf8());
    }
}


void MainWindow::on_pushButton_clicked()
{
    //设置服务器监听的地址和端口
    tcpServer->listen(QHostAddress("192.168.93.1"), 1900);

}


void MainWindow::on_pushButton_2_clicked()
{
    tcpServer->close();
}

