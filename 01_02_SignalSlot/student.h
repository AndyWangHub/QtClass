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
    //早期Qt版本 槽函数必须写到 public slots:
    //高的版本可以写在 public 或全局函数
    //返回值 void，需要声明，也需要实现
    //可以有参数，可以重载
    void treat();

    void treat(QString foodName);

};

#endif // STUDENT_H
