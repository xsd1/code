#include "ticketbuy.h"
#include "ui_ticketbuy.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
TicketBuy::TicketBuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketBuy)
{
    ui->setupUi(this);
    connect(ui->pushButton_back,&QPushButton::clicked,this,&TicketBuy::sendSlot_2);
    connect(ui->pushButton_yes,&QPushButton::clicked,this,&TicketBuy::save);
}

TicketBuy::~TicketBuy()
{
    delete ui;
}
void TicketBuy::sendSlot_2()
{
    emit Mysignal_2();
}
void TicketBuy::save()
{
    start = ui->lineEdit_start->text();
    end = ui->lineEdit_end->text();
    id = ui->lineEdit_id->text();
    name = ui->lineEdit_name->text();
    phone = ui->lineEdit_phone->text();
    QString filename;
    QFile files("../文件名.txt");
    bool isok = files.open(QIODevice::ReadOnly);
    if(isok == true)
    {
        QTextStream stream(&files);
        stream >>filename;
        files.close();
    }
    else filename = "passenger.info";
    int price = 0,i = 0;
    while(i<9)
    {
        if(start <= station[i]&&end > station[i])price += array[i];
        i++;
    }
    QString filename1 = filename + '1';
    QFile file("../" + filename1 + ".txt");
    isok = file.open(QIODevice::WriteOnly);
    if(isok ==true)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << start << " " << end << " " << id << " " << name << " " << price << " " << phone;
        file.close();
    }
    isok = files.open(QIODevice::WriteOnly);
    if(isok == true)
    {
        QTextStream stream(&files);
        stream << filename1;
        files.close();
    }
    QMessageBox::about(this,"在线购票","购票成功");
    return;
}
