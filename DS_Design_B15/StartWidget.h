#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "choosedatastructure.h"

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = 0);
    ~StartWidget();

    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *event);

    ChooseDataStructure *choice = nullptr;

private:
    Ui::StartWidget *ui;
};

#endif // WIDGET_H
