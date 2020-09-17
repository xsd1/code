#include "ticketbuy.h"
#include "ui_ticketbuy.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
TicketBuy::TicketBuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketBuy)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    setWindowTitle("购票窗口");
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
    ui->lineEdit_id->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_phone->setText("");
}
void TicketBuy::save()
{
    TicketBuy tb;
    tb.start = ui->comboBox_start->currentText();
    tb.end = ui->comboBox_end->currentText();
    tb.id = ui->lineEdit_id->text();
    tb.name = ui->lineEdit_name->text();
    tb.phone = ui->lineEdit_phone->text();
    if(tb.check() == false)
    {
        QMessageBox::information(this,"填写信息","填写信息有误");
        return;
    }
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
    int i = 0;
    tb.price = 0;
    while(i<9)
    {
        if(tb.start <= station[i]&&tb.end > station[i])tb.price += array[i];
        i++;
    }
    QString filename1 = filename + '1';
    QFile file("../" + filename1 + ".txt");
    isok = file.open(QIODevice::WriteOnly);
    if(isok ==true)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << tb.start << " " << tb.end << " " << tb.id << " " << tb.name << " " << tb.price << " " << tb.phone;
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
bool TicketBuy::check()
{
    int i = 0;
    if(this->end != "A10"&&this->start >= this->end)
        return false;
    if(this->phone.length() != 11||this->id.length() != 18)
        return false;
    i = 0;
    while(i < 11)
    {
        if(this->phone[i] < 48||this->phone[i] > 57)
            return false;
        i++;
    }
    i = 0;
    while(i < 18)
    {
        if(this->id[i] < 48 ||this->id[i] > 57)
            return false;
        i++;
    }
    return true;
}
