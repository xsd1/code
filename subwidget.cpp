#include "subwidget.h"

subWidget::subWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("界面1");
    b1.setParent(this);
    b1.setText("继续购票");
    b1.move(100,100);
    b2.setParent(this);
    b2.setText("返回到主窗口");
    b2.move(300,100);
    connect(&b2,&QPushButton::clicked,this,&subWidget::sendSlot);
    connect(&b1,&QPushButton::released,this,&subWidget::changewin);
    connect(&w1,&subWidget1::mysingal1,this,&subWidget::dealsub1);
}
void subWidget::sendSlot()
{
    emit mysingal();
}
void subWidget::changewin()
{
    this->hide();
    w1.show();
}
void subWidget::dealsub1()
{
    w1.hide();
    this->show();
}
