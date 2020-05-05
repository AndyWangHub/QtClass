#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn1 = new QPushButton("Open",this);
    QPushButton *btn2 = new QPushButton("Close",this);
    QPushButton *btn3 = new QPushButton("open",this);
    btn2->move(100,0);
    btn3->move(200,0);
    this->resize(600,400);

    connect(btn1,&QPushButton::clicked,[=](bool b){
        this->wd = new QWidget;
        wd->resize(200,100);
        wd->show();
        qDebug()<<b;

    });

    connect(btn2,&QPushButton::clicked,[=](){
        wd->close();
    });


    connect(btn3,&QPushButton::toggled,[=](bool b){
        qDebug()<<b;
        if(b){
            btn3->setText("close");
            this->wd = new QWidget;
            wd->resize(200,100);
            wd->show();
        }
        else {
            btn3->setText("open");
            wd->close();
        }
    });

    btn3->setCheckable(true);//
}

Widget::~Widget()
{
}

