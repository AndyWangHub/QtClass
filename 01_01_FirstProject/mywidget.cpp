/*
 * 命名规范
 * 类名 首字母大写，单词和单词之间首字母大写
 * 函数名 变量名称 首字母小写，单词和单词之间首字母大写
*/

/*
 * 快捷键
 * 注释 Ctrl + /
 * 运行 Ctrl + r
 * 编译 ctrl + b
 * 字体缩放 ctrl + 鼠标滚轮
 * 查找 ctrl + f
 * 整体移动 ctrl + shift + 上下移动符号
 * 帮助文档 F1
 * 自动对齐 ctrl + i
 * 同名之间的.h和.cpp却换 F4
 *
 * 帮助文档 第一种 F1，第二种 左侧按钮， 第三种Qt助手 C:\Qt\5.12.6\mingw73_32\bin
*/

#include "mywidget.h"
#include "QPushButton"
#include "QDebug"
#include "mypushbutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    //show以顶层方式弹出窗口控件
    //btn->show();
    btn->setParent(this);

    //显示文旦
    btn->setText("第一个按钮");

/**********************************************************/
    //创建第二个按钮 按照控件的大小创建
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,200);

/**********************************************************/
    //重置窗口大小
    this->resize(600,400);
    //设置固定的窗口大小
    this->setFixedSize(600,400);
    //设置窗口标题
    this->setWindowTitle("第一个窗口");
/**********************************************************/
    //对象树析构测试

    MyPushButton *btn3 = new MyPushButton(this);
    btn3->setText("对象树按钮");
    btn3->move(100,0);

    //需求：点击我的按钮 关闭窗口
    //参数1 信号的发送者 参数2 发送的信号(函数地址)
    //参数3 信号的接收这 参数4 处理的槽函数
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
}

MyWidget::~MyWidget()
{
    qDebug()<<"MyWidget析构函数";
}

