#include "mywidget.h"
#include <QPushButton>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("火车票查询");
    b1.move(100,100);
    b2.setParent(this);
    b2.setText("退票");
    b2.move(200,100);
    b3.setParent(this);
    b3.setText("退出");
    b3.move(150,200);
    connect(&b3,&QPushButton::pressed,this,&MyWidget::close);
    setWindowTitle("主界面");
    //w.show();
    connect(&b1,&QPushButton::released,this,&MyWidget::changewin);
    connect(&w,&subWidget::mysingal,this,&MyWidget::dealsub);
    connect(&b2,&QPushButton::released,this,&MyWidget::changewin2);
    connect(&w2,&subWidget2::mysingal2,this,&MyWidget::dealsub2);
}
void MyWidget::changewin()
{
    w.show();
    this->hide();
}
void MyWidget::dealsub()
{
    w.hide();
    this->show();
}
void MyWidget::changewin2()
{
    w2.show();
    this->hide();
}
void MyWidget::dealsub2()
{
    w2.hide();
    this->show();
}
MyWidget::~MyWidget()
{

}
