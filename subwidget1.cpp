#include "subwidget1.h"

subWidget1::subWidget1(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("购票窗口");
    b.setParent(this);
    b.setText("返回");
    b.move(100,100);
    connect(&b,&QPushButton::clicked,this,&subWidget1::sendSlot1);
}
void subWidget1::sendSlot1()
{
    emit mysingal1();
}
