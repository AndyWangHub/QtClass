#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->setText("abcd\n");
    //ui->textEdit->setText("123");

    //插入纯文本
    ui->textEdit->insertPlainText("test");
}

Widget::~Widget()
{
    delete ui;
}

