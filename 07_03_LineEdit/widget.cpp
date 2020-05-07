#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*QLineEdit 有4种显示模式(echoMode)
     * 1.Normal 正常显示输入
     * 2.NoEcho 不显示任何输入
     * 3.Password 显示为密码模式，就是以小黑点或星号之类的字符串代替输入的字符位数
     * 4.PasswEchoOnEdit 在编辑时正常显示字符，其实情况下显示密码模式
    */

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<<"text: "<<ui->lineEdit->text();
    qDebug()<<"placeholderText: "<<ui->lineEdit->placeholderText();
    qDebug()<<"displayText: "<<ui->lineEdit->displayText();
    qDebug()<<"inputMask: "<<ui->lineEdit->inputMask();
    qDebug()<<"selectedText: "<<ui->lineEdit->selectedText();
}
