#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    setWindowTitle("火车票在线购票系统");
    connect(&ts,&Ticketsearch::Mysignal_1,this,&Widget::dealSlot_1);
    connect(&tb,&TicketBuy::Mysignal_2,this,&Widget::dealSlot_2);
    connect(&tfs,&Ticketinfosearch::Mysignal_3,this,&dealSlot_3);
    connect(&rt,&Returnticket::Mysignal_4,this,&Widget::dealSlot_4);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->hide();
    ts.show();
}
void Widget::dealSlot_1()
{
    this->show();
    ts.hide();
}
void Widget::on_pushButton_2_clicked()
{
    this->hide();
    tb.show();
}
void Widget::dealSlot_2()
{
    this->show();
    tb.hide();
}

void Widget::on_pushButton_3_clicked()
{
    this->hide();
    tfs.show();
}
void Widget::dealSlot_3()
{
    this->show();
    tfs.hide();
}

void Widget::on_pushButton_4_clicked()
{
    this->hide();
    rt.show();
}
void Widget::dealSlot_4()
{
    this->show();
    rt.hide();
}
