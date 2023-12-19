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
    //配置一下
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

    mainwindow = new MainWindow;

    //hush按钮
    connect(hushPushButton, &QPushButton::clicked, [=]() {
     //延迟进入
      QTimer::singleShot(200, this, [=]() {
          //创建一个散列表，进入到词典查询页面，并且将自身隐藏
          Hush *hush_table = new Hush();
          this->hide();
          mainwindow->show();

          //插入操作与Hush的连接
          connect(mainwindow->getInsertButton(), &QPushButton::clicked, [=]() {
              //打开存有词典的all.txt文件
              freopen("C:\\Users\\27646\\Desktop\\project_res\\data-structure-course-design-master\\data-structure-course-design-master\\NewDataStructure\\English\\all.txt", "r", stdin);
              string key, value;
              while(cin >> key >> value) {
                hush_table->insert(key, value);
              }
              QMessageBox::information(this, "插入单词操作", "Hush数据结构已经插入所有单词");
          });

          //删除操作与Hush的连接
          connect(mainwindow->getDeleteButton(), &QPushButton::clicked, [=]() {
             //获取删除单词文本框内的文本——要删除键值对的键
             QString res = mainwindow->getWord2()->text();
             string temp = res.toStdString();
             //如果哈希表中存在这个键，则进行删除操作
             if(hush_table->find(temp) != "未找到该单词") {
                 hush_table->deleteKey(temp);
                 mainwindow->getDeleteEdit()->setText("删除成功");
                 QMessageBox::information(this, "删除单词操作", QString::fromStdString(temp) + "已经删除");
             }
             //否则提示删除失败
             else {
                 QMessageBox::information(this, "删除单词操作", "字典中不存在该单词");
                 mainwindow->getDeleteEdit()->setText("未找到该单词");
             }
          });

          //连接翻译按钮点击信号的槽函数
          connect(mainwindow->getTranslateButton(), &QPushButton::clicked, [=]() {
             QString res = mainwindow->getWord1()->text();
             string temp = res.toStdString();
             //在哈希表中查询输入键，查询成果返回对应的值，查询失败则返回“未找到该单词”
             string ret_value = hush_table->find(temp);
             QMessageBox::information(this, "查找操作", "单词已经查找完成");
             mainwindow->getTranslateEdit()->setText(QString::fromStdString(ret_value));
          });

          // 连接插入文本按钮的信号和槽
          connect(mainwindow->getInsertTextBtn(), &QPushButton::clicked, [=]() {
              QFile file("C:/Users/27646/Desktop/github_clone/DS_Design_B15/res/1.txt");
              if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                  QMessageBox::warning(this, "错误", "无法打开文件");
                  return;
              }

              QTextStream in(&file);
              QString word;
              map<QString, int> wordFrequency; // 使用 QString 代替 string

              // 读取文件中每个词
              while (!in.atEnd()) {
                  in >> word;
                  // 判断读取到的词是否合法（即是否在字典范围内）
                  if (hush_table->find(word.toStdString()) != "未找到该单词") {
                      wordFrequency[word]++;
                  } else {
                      continue;
                  }
              }

              // 将合法单词的频率显示在 QListWidget:WordFrequencyList 上
              QListWidget *listWidget = mainwindow->getWordFrequencyList();
              map<QString, int>::const_iterator map_it;
              for (map_it = wordFrequency.begin(); map_it != wordFrequency.end(); ++map_it) {
                  QString itemText = QString("(\"%1\", %2)").arg(map_it->first).arg(map_it->second);
                  listWidget->addItem(itemText);
              }

              file.close(); // 关闭文件
          });

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
