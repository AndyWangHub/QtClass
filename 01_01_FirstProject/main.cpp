#include "mywidget.h"

#include <QApplication>

//main程序入口
int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，应用程序对象 有且仅有一个
    QApplication a(argc, argv);
    //窗口对象
    MyWidget w;
    //窗口对象默认不会显示，必须要调用show方法显示窗口
    w.show();

    //让应用程序对象进入消息循环
    //当代码阻塞到这行
    return a.exec();
}
