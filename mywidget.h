#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"
#include "subwidget2.h"
class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void changewin();
    void dealsub();
    void changewin2();
    void dealsub2();
private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    subWidget w;
    subWidget2 w2;
};

#endif // MYWIDGET_H
