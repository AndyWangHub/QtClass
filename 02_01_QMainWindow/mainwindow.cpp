#include "mainwindow.h"
#include <QMenuBar> //菜单栏
#include <QToolBar> //工具栏
#include <QStatusBar> //状态栏
#include <QDockWidget> //铆接部件
#include <QTextEdit> //

#include <QPushButton> //按钮
#include <QLabel> //标签
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    this->resize(600,400);

    /*********************************************************/
    //菜单栏创建(菜单栏，只能最多有一个)
    QMenuBar *bar = this->menuBar();
    //将菜单栏放入窗口中
    this->setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction * newAction = fileMenu->addAction("新建");
    //添加分割线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    /*********************************************************/
    //工具栏 可以有多个
    QToolBar *toolBar = new QToolBar(this);
    //this->addToolBar(toolbar);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    //后期设置 只允许 左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    toolBar->setFloatable(false);

    //设置移动（总开关）
    toolBar->setMovable(false);

    //工具栏中可以设置内容
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //工具栏添加控件
    QPushButton * btn = new QPushButton("abc",this);
    toolBar->addWidget(btn);

    /*********************************************************/
    //状态栏 最多有一个
    QStatusBar * stBar = this->statusBar();
    //设置到窗口中
    this->setStatusBar(stBar);
    //放标签控件
    QLabel * label = new QLabel("提示信息",this);
    stBar->addWidget(label);

    QLabel * label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);

    /*********************************************************/
    //铆接部件（浮动窗口） 可以有多个
    QDockWidget * dockWidget = new QDockWidget("浮动",this);
    this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置后期停靠区域 只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //设置中心部件，只能一个
    QTextEdit *edit = new QTextEdit(this);
    this->setCentralWidget(edit);

    /*********************************************************/

}

MainWindow::~MainWindow()
{
}

