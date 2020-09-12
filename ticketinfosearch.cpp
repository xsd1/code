#include "ticketinfosearch.h"
#include "ui_ticketinfosearch.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QTextStream>
Ticketinfosearch::Ticketinfosearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ticketinfosearch)
{
    ui->setupUi(this);
    ui->label_start->hide();
    ui->label_end->hide();
    ui->label_price->hide();
    connect(ui->pushButton_back,&QPushButton::clicked,this,&Ticketinfosearch::sendSlot_3);
    connect(ui->pushButton_yes,&QPushButton::clicked,this,&Ticketinfosearch::search);
}

Ticketinfosearch::~Ticketinfosearch()
{
    delete ui;
}
void Ticketinfosearch::sendSlot_3()
{
    emit Mysignal_3();
}
void Ticketinfosearch::search()
{
    QString str1 = ui->lineEdit->text();//输入信息
    QString str2 =ui->label_id->text();//比较对象的内容
    QString filename = "passenger.info";
    QString filename1;
    QFile files("../文件名.txt");
    bool isok = files.open(QIODevice::ReadOnly);
    if(isok == true)
    {
        QTextStream stream(&files);
        stream >> filename1;
        files.close();
    }
    else filename1 = filename;
    while(filename != filename1)
    {
        filename = filename + '1';
        QFile file("../" + filename + ".txt");
        isok = file.open(QIODevice::ReadOnly);
        if(isok == true)
        {
            QTextStream stream(&file);
            stream >> start >> end >> id >> name >> price;
            if(str2 == "身份证" && str1 == id)               //比对信息
            {
                ui->label_start->setText(start);
                ui->label_end->setText(end);
                str1 = QString("%1").arg(price) + "元";
                ui->label_price->setText(str1);
                ui->label_start->show();
                ui->label_end->show();
                ui->label_price->show();
                return;
            }
            file.close();

        }

    }
    QMessageBox::about(this,"车票信息查询","未查询到购票记录");

}
