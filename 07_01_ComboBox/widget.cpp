#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList texts;
    texts<<"127.0.0.1"
        <<"192.168.0.1"
       <<"0.0.0.0";
    ui->comboBox->addItems(texts);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_comboBox_activated(const QString &arg1)
{
    qDebug()<<"activate string: "<<arg1;
}

void Widget::on_comboBox_activated(int index)
{
    qDebug()<<"activate int: "<<index;
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<"currentIndexChanged string: "<<arg1;
}

void Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug()<<"currentTextChanged string: "<<arg1;
}

void Widget::on_comboBox_editTextChanged(const QString &arg1)
{
    qDebug()<<"editTextChanged string: "<<arg1;
}

void Widget::on_comboBox_textActivated(const QString &arg1)
{
    qDebug()<<"textActivated string: "<<arg1;
}

void Widget::on_comboBox_highlighted(const QString &arg1)
{
    qDebug()<<"highlighted string: "<<arg1;
}

void Widget::on_pushButton_clicked(bool checked)
{
    qDebug()<<"currentText: "<<ui->comboBox->currentText();
}
