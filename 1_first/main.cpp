#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv),管理Qt程序的运行，和设置Qt应用程序，针对QWidget应用程序

    // QGuiApplication a(argc, argv),管理Qt程序的运行，和设置Qt应用程序，针对非QWidget应用程序，比如Quick

    // QCoreApplication a(argc, argv),管理Qt程序的运行，和设置Qt应用程序，针对无界面的应用程序
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //返回一个事件循环，等待鼠标、键盘等输入，触发事件
    return QApplication::exec();
}
