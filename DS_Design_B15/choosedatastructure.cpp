#include "choosedatastructure.h"
#include "hush.h"
#include "mainwindow.h"
#include <bits/stdc++.h>
using namespace std;
#include <QMenuBar>
#include <QPainter>
#include<QPushButton>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QListWidget>
#include <map>

ChooseDataStructure::ChooseDataStructure(QWidget *parent) : QMainWindow(parent) {
    //配置一下窗口大小
    this->setFixedSize(800, 588);
    //设置图标
    this->setWindowIcon(QIcon(":/res/cidian.jpg"));
    //设置标题
    this->setWindowTitle("选择数据结构");
    //创建菜单栏
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    //创建退出
    QAction *quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=]() {
       this->close();
    });

    QFont font("Microsoft YaHei", 10, 75);

    QPushButton *hushPushButton = new QPushButton("Hush数据结构");
    hushPushButton->setParent(this);
    hushPushButton->resize(150, 50);
    hushPushButton->move(300, 300);
    hushPushButton->show();
    hushPushButton->setFlat(false);
    hushPushButton->setFont(font);

    QPushButton *hushPushButton1 = new QPushButton("字典树数据结构");
    hushPushButton1->setParent(this);
    hushPushButton1->resize(150, 50);
    hushPushButton1->move(300, 400);
    hushPushButton1->show();
    hushPushButton1->setFlat(false);
    hushPushButton1->setFont(font);

    //创建新的操作界面
    mainwindow = new MainWindow;

    //hush按钮
    connect(hushPushButton, &QPushButton::clicked, [=]() {
     //延迟进入
      QTimer::singleShot(200, this, [=]() {

          this->hide();
          mainwindow->init();
          mainwindow->show(); 

      });
    });
}

//重写绘制函数
void ChooseDataStructure::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    //绘制背景
    QPixmap pix;
    pix.load(":/res/mu.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
