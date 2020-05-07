#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QMenu *meun = new QMenu(this);
    meun->addAction("放大");
    ui->pushButton_3->setMenu(meun);

    //设置隐藏
    //ui->groupBox->setHidden(true);

    ui->pushButton->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked(bool checked)
{
    qDebug()<<"cheched: "<<checked;
    ui->pushButton->setChecked(true);
}
