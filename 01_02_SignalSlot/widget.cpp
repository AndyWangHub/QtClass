#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
/*
 * Teacher 类
 * Student 类
 * 下课后，老师触发一个信号，俄了，学生相应信号，请客吃饭
*/
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);
    //创建一个学生对象
    this->st = new Student(this);

//    //老师饿了，学生请客的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//    this->classIsOver();

    //连接带参数的 信号和槽
    //指针 -> 地址
    //函数指针 -> 函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
    this->classIsOver();

    //点击一个 下课按钮 ，再触发下课
    QPushButton *btn = new QPushButton("下课",this);
    this->resize(600,400);
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //点击一个按钮触发一个信号
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);

     //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);
    //断开信号与槽
    //disconnect(zt,teacherSignal2,st,studentSlot2);

    //拓展
    //1.信号可以连接信号
    //2.一个信号可以连接多个槽函数
    //3.多个信号可以连接对个槽函数
    //4.信号和槽函数的类型一样对应
    //5.信号和槽的函数参数可以不一致（信号的参数比槽函数的多一个）

    //Qt4版本以前的信号和槽的连接
    //connect(zt,SIGNAL(hungry()),st,SLOT(treat(QString)));
    //Qt4
}

Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver()
{
    //下课函数，调用后 触发老师俄了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

