#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("英汉词典");
    this->setWindowIcon(QIcon(":/res/cidian.jpg"));
    ui->setupUi(this);
    ui->deleteEdit->setEnabled(false);
    ui->translationEdit->setEnabled(false);
    ui->deleteButton->setFlat(false);
    ui->insertButton->setFlat(false);
    ui->translateButton->setFlat(false);
    ui->InsertTextBtn->setFlat(false);
    ui->WordFrequencyList->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//重写绘制函数
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    //绘制背景
    QPixmap pix;
    pix.load(":/res/nuan.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

QPushButton* MainWindow::getInsertButton() {
    return ui->insertButton;
}

QPushButton* MainWindow::getDeleteButton() {
    return ui->deleteButton;
}

QPushButton* MainWindow::getTranslateButton() {
    return ui->translateButton;
}


QLineEdit* MainWindow::getWord1() {
    return ui->words1;
}

QLineEdit* MainWindow::getWord2() {
    return ui->words2;
}

QTextEdit* MainWindow::getTranslateEdit() {
    return ui->translationEdit;
}

QTextEdit* MainWindow::getDeleteEdit() {
    return ui->deleteEdit;
}

QPushButton* MainWindow::getInsertTextBtn() {
    return ui->InsertTextBtn;
}

QListWidget* MainWindow::getWordFrequencyList() {
    return ui->WordFrequencyList;
}
