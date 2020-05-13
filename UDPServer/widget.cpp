#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QtNetwork>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    //获取主机名
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug()<<"localHostName"<<localHostName<<endl
           <<" IP Address: "<<info.addresses();

    QStringList addrList;
    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug()<<address.toString();
            addrList<<address.toString();
        }
    }
    ui->comboBox_ip->addItems(addrList);
    addrList.clear();
    addrList<<"5200"<<"2046";
    ui->comboBox_port->addItems(addrList);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_key_clicked(bool checked)
{
    qDebug()<<"checked: "<<checked;
    if(checked)
    {
        QHostAddress addr(ui->comboBox_ip->currentText());
        if(udpSocket->bind(addr,ui->comboBox_ip->currentText().toUInt()))
        {
            ui->pushButton_key->setText("关闭");
            ui->pushButton_key->setChecked(true);
        }
        else
        {
            ui->pushButton_key->setChecked(false);
        }
    }else
    {
        ui->pushButton_key->setText("打开");
    }
}
