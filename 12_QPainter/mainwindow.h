#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

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
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
    QFont font;
    int offset;
    QTimer *timer;
    QString str = "Hello from qt  Hello from qt  Hello from qt";
    int strWidth;
private slots:
    void onTimerTimeout();
};
#endif // MAINWINDOW_H
