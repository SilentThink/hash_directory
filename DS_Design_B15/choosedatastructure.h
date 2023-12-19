#ifndef CHOOSEDATASTRUCTURE_H
#define CHOOSEDATASTRUCTURE_H

#include <QMainWindow>
#include "mainwindow.h"

class ChooseDataStructure : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseDataStructure(QWidget *parent = nullptr);

    //重写绘图实现
    void paintEvent(QPaintEvent *event);

    MainWindow *mainwindow = nullptr;
signals:

public slots:
};

#endif // CHOOSEDATASTRUCTURE_H
