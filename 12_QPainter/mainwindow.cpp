#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPolygon>
#include <QPainterPath>
#include <QFontMetrics>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    font.setPixelSize(50);
    QFontMetrics fontMetircs(font);
    strWidth = fontMetircs.horizontalAdvance(str);
    offset = 800;
    timer = new QTimer(this);
    timer->start(10);
   connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColorConstants::Red);
    // pen.setWidth(10);

    // QBrush brush(QColor(200, 100, 50));
    // painter.setBrush(brush);

    // painter.drawRect(200, 100, 100, 100);
    // painter.setRenderHint(QPainter::Antialiasing);//抗锯齿

    // QPolygon polygon;
    // polygon.setPoints(3, 100, 20, 200, 50, 300);

    // painter.drawPolygon(polygon);

    // QPainterPath path;
    // path.moveTo(20, 80);
    // path.cubicTo(80, 0, 50, 50, 80, 80);
    // painter.drawPath(path);
    QRectF rectF = this->rect();
    rectF.setLeft(this->width() - offset);//设置最左边的坐标

    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(rectF, Qt::AlignVCenter, str);




}

void MainWindow::onTimerTimeout()
{
    if(offset < this->width() + strWidth)
        offset += 1;
    else{
        offset = 0;
    }
    this->update();
}
