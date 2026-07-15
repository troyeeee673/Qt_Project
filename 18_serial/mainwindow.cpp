#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialPort = new QSerialPort(this);
    //遍历所有串口信息
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName());//添加串口选项到下拉选择框
    }
    //有数据到来时触发读数据函数
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    if(checked)
    {
        //设置要打开的串口的名字
        serialPort->setPortName(ui->comboBox->currentText());
        //设置波特率
        serialPort->setBaudRate(ui->comboBox_2->currentText().toInt());
        //设置停止位
        serialPort->setStopBits(QSerialPort::StopBits(ui->comboBox_3->currentText().toInt()));
        //设置数据位
        serialPort->setDataBits(QSerialPort::DataBits(ui->comboBox_4->currentText().toInt()));
        //设置校验位
        serialPort->setParity(QSerialPort::Parity(ui->comboBox_5->currentText().toInt()));
        //设置流控
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if(!serialPort->open(QIODevice::ReadWrite))
        {
            QMessageBox::about(this, "错误", "串口打开失败");
        }
        ui->comboBox_5->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->comboBox_4->setEnabled(false);

        ui->pushButton->setText("关闭串口");
    }
    else{
        ui->comboBox_5->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->pushButton->setText("打开串口");
    }
}

void MainWindow::readData()
{
    ui->textBrowser->setPlainText(serialPort->readAll());
}


void MainWindow::on_pushButton_2_clicked()
{
    serialPort->write(ui->textEdit->toPlainText().toUtf8());
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
}

