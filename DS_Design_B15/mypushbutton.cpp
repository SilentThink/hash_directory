#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent) {

}

MyPushButton::MyPushButton(QString normalImage, QString pressImage) {
    this->normalImagePath = normalImage;
    this->pressImagePath = pressImage;

    QPixmap pix;
    bool ret = pix.load(normalImage);
    if(!ret) {
        qDebug() << "图片加载失败";
        return ;
    }
    //设置固定的大小
    this->setFixedSize(150, 70);
    //设置图标
    this->setIcon(pix);
    //设置图标的大小
    this->setIconSize(QSize(150, 70));
}


void MyPushButton::zoom1() {
    //创建图画特效
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::zoom2() {
    //创建图画特效
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
