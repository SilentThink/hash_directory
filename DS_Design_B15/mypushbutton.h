#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QDebug>
//仅作美化用途

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    //参数1为正常显示的图片路径 参数2为按下后的图片的路径
    MyPushButton(QString normalImage, QString pressImage = "");

    //成员函数 保存下来路径
    QString normalImagePath;
    QString pressImagePath;

    //弹跳特效
    void zoom1();  //向下跳
    void zoom2();  //向上跳

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
