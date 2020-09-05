#include "subwidget2.h"

subWidget2::subWidget2(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("退票窗口");
    b.setParent(this);
    b.setText("返回");
    b.move(100,100);
    connect(&b,&QPushButton::clicked,this,&subWidget2::sendSlot2);
}
void subWidget2::sendSlot2()
{
    emit mysingal2();
}
