#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:
public slots:
    void comeBackToClass();//定义槽,需要在cpp中定义

};

#endif // STUDENT_H
