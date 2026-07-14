#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 开发板的led接口
    file.setFileName("/sys/class/leds/sys-led/brightness");
    // trigger：LED 触发模式文件，用来设置 LED 自动闪烁逻辑：
    // 写入0 / none：关闭自动触发，LED 由brightness手动控制（最常用）；
    // 其他可选值：heartbeat心跳闪烁、timer定时闪烁、mmc读写硬盘闪烁等
    system("echo 0 > /sys/class/leds/sys-led/trigger");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    qDebug()<<checked<<Qt::endl;
    //驱动层接口不存在，提醒用户
    if(!file.exists())
    {
        qDebug()<<"led接口不存在"<<Qt::endl;
        return;
    }
    if(!file.open(QIODevice::WriteOnly))
        return ;
    QByteArray buf[] = {"0", "1"};
    if(checked)
    {
        ui->pushButton->setText("关");
        file.write(buf[1]);
    }
    else
    {
        ui->pushButton->setText("开");
        file.write(buf[0]);
    }
    file.close();
}

