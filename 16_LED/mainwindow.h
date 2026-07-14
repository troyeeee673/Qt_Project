#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>//因为Linux中一切皆文件，所以通过QFile来访问驱动层提供的接口，控制LED亮灭

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QFile file;
};
#endif // MAINWINDOW_H
