#ifndef SCHOOL_H
#define SCHOOL_H

#include <QObject>

class School : public QObject
{
    Q_OBJECT
public:
    explicit School(QObject *parent = nullptr);

signals://信号关键字
    void sendMessages();


};

#endif // SCHOOL_H
