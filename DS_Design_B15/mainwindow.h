#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QListWidget>
#include "hush.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

    QPushButton* getInsertButton();

    QPushButton* getDeleteButton();

    QPushButton* getTranslateButton();

    QLineEdit* getWord1();

    QLineEdit* getWord2();

    QTextEdit* getTranslateEdit();

    QTextEdit* getDeleteEdit();

    QPushButton* getInsertTextBtn();

    QListWidget* getWordFrequencyList();

    void init();

    //创建一个散列表
    Hush *hush_table = new Hush();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
