#ifndef CHOICE_H
#define CHOICE_H

#include <QWidget>

namespace Ui {
class Choice;
}

class Choice : public QWidget
{
    Q_OBJECT

public:
    explicit Choice(QWidget *parent = 0);
    ~Choice();

private:
    Ui::Choice *ui;
};

#endif // CHOICE_H
