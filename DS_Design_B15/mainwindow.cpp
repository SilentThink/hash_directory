#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QWidgetList>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

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
    ui->WordFrequencyList->setEnabled(true);
    ui->WordFrequencyList->setFlow(QListView::TopToBottom);
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

void MainWindow::init()
{
    //插入操作与Hush的连接
    connect(ui->insertButton, &QPushButton::clicked, [=]() {
        //打开存有词典的all.txt文件
        freopen("C:\\Users\\27646\\Desktop\\project_res\\data-structure-course-design-master\\data-structure-course-design-master\\NewDataStructure\\English\\all.txt", "r", stdin);
        string key, value;
        while(cin >> key >> value) {
          hush_table->insert(key, value);
        }
        QMessageBox::information(this, "插入单词操作", "Hush数据结构已经插入所有单词");
    });

    //删除操作与Hush的连接
    connect(ui->deleteButton, &QPushButton::clicked, [=]() {
       //获取删除单词文本框内的文本——要删除键值对的键
       QString res = ui->words2->text();
       string temp = res.toStdString();
       //如果哈希表中存在这个键，则进行删除操作
       if(hush_table->find(temp) != "未找到该单词") {
           hush_table->deleteKey(temp);
           ui->deleteEdit->setText("删除成功");
           QMessageBox::information(this, "删除单词操作", QString::fromStdString(temp) + "已经删除");
       }
       //否则提示删除失败
       else {
           QMessageBox::information(this, "删除单词操作", "字典中不存在该单词");
           ui->deleteEdit->setText("未找到该单词");
       }
    });

    //连接翻译按钮点击信号的槽函数
    connect(ui->translateButton, &QPushButton::clicked, [=]() {
       QString res = ui->words1->text();
       string temp = res.toStdString();
       //在哈希表中查询输入键，查询成果返回对应的值，查询失败则返回“未找到该单词”
       string ret_value = hush_table->find(temp);
       QMessageBox::information(this, "查找操作", "单词已经查找完成");
       ui->translationEdit->setText(QString::fromStdString(ret_value));
    });

    // 插入文本，词频统计
    connect(ui->InsertTextBtn, &QPushButton::clicked, [=]() {
        ui->WordFrequencyList->clear();
        auto strPath = QFileDialog::getOpenFileName(nullptr,"输入文件路径");

        QFile file(strPath);
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
        QListWidget *listWidget = ui->WordFrequencyList;
        map<QString, int>::const_iterator map_it;
        for (map_it = wordFrequency.begin(); map_it != wordFrequency.end(); ++map_it) {
            QString itemText = QString("(\"%1\", %2)").arg(map_it->first).arg(map_it->second);
            listWidget->addItem(itemText);
        }

        file.close(); // 关闭文件
    });
}
