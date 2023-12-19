#include "StartWidget.h"
#include "choice.h"
#include "ui_StartWidget.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QTimer>

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidget)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(800, 588);
    //设置标题旁的图标
    this->setWindowIcon(QIcon(":/res/cidian.jpg"));
    //设置窗口标题
    this->setWindowTitle("英汉词典");

    //设置开始图标
    MyPushButton *start = new MyPushButton(":/res/newStart.png");
    start->setParent(this);
    //弹起效果
    start->move(this->width() * 0.5 - start->width() * 0.5, this->height() * 0.7);

    choice = new ChooseDataStructure;

    connect(start, &MyPushButton::clicked, [=]() {
        start->zoom1();
        start->zoom2();
        //延迟进入
        QTimer::singleShot(200, this, [=]() {
            //进入到相关页面 并且将自身隐藏
            this->hide();
            choice->show();
        });
    });
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix;
    //绘制背景图片
    pix.load(":/res/HelloWorld.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/name.png");
    painter.drawPixmap(120, 0, pix);
}
