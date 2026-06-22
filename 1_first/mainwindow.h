#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "School.h"
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class Stduent;
class School;

class MainWindow : public QMainWindow
{
    //信号槽需要使用
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    int i;

private slots:
    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;
    Student *student;
    School *school;
};
#endif // MAINWINDOW_H
