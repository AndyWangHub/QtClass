#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QToolButton>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /****************************************/
    //QPushButton 一般用来显示文字
    //激活按钮的信号功能（参数true和false）
    ui->pushButton->setCheckable(true);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](bool checked){
        qDebug()<<"clicked_checked:"<<checked;
        qDebug()<<"isCheckable:"<<ui->pushButton->isCheckable();

        //clicked信号设置按钮是否显示按下
        ui->pushButton->setChecked(checked);

    });

    ui->pushButton_2->setCheckable(true);
    connect(ui->pushButton_2,&QPushButton::toggled,this,[=](bool checked){
        qDebug()<<"toggled_checked:"<<checked;
        qDebug()<<"isCheckable:"<<ui->pushButton_2->isCheckable();

        //toggled信号无需设置按钮是否显示按下
         //ui->pushButton_3->setChecked(checked);

    });

    ui->pushButton_3->setCheckable(true);
    connect(ui->pushButton_3,&QPushButton::pressed,this,[](){
        qDebug()<<"pressed 按钮按下";
    });

    ui->pushButton_3->setCheckable(true);
    connect(ui->pushButton_3,&QPushButton::released,this,[](){
        qDebug()<<"released 按钮松开";
    });

    /****************************************/
    //QToolButton 一般用来显示图片或图片加文字（功能和PushButton类似）
    ui->toolButton->setCheckable(true);
    connect(ui->toolButton,&QToolButton::toggled,this,[=](bool checked){
        if(checked)
        {
            ui->toolButton->setIcon(QIcon(":/Image/Sunny.jpg"));
            ui->toolButton->setText("海贼船");
        }
        else
        {
            ui->toolButton->setIcon(QIcon(":/Image/OnePiece.png"));
            ui->toolButton->setText("海贼旗");
        }
    });

    /****************************************/
    //QRadioButton --单选按钮
    //设置默认选项
    ui->radioButton->setChecked(true);
    connect(ui->radioButton_2,&QRadioButton::clicked,[=](bool checked){
        qDebug()<<"radioButton_2"<<checked;
    });

    //QCheckBox --多选按钮
    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<"stateChanged_state:"<<state;
    });

    /****************************************/
//    //利用listWidget
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    //将一行诗放入到listWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    QStringList list;
    list<<"锄禾日当午"<<"旱地和下土"<<"谁知盘中餐";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

