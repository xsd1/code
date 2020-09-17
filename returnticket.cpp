#include "returnticket.h"
#include "ui_returnticket.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
Returnticket::Returnticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Returnticket)
{

    ui->setupUi(this);
    setWindowTitle("退票窗口");
    connect(ui->pushButton_back,&QPushButton::clicked,this,&Returnticket::sendSlot_4);
    connect(ui->pushButton_yes,&QPushButton::clicked,this,&Returnticket::ticketreturn);
}

Returnticket::~Returnticket()
{
    delete ui;
}
void Returnticket::sendSlot_4()
{
    emit Mysignal_4();
    ui->lineEdit->setText("");

}
void Returnticket::ticketreturn()
{
    QString str = ui->lineEdit->text();
    QString filename = "passenger.info";
    int flag = 0;
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

    while (filename != filename1)
    {
        filename = filename + '1';
        QFile file("../" + filename + ".txt");
        isok = file.open(QIODevice::ReadOnly);
        if(isok == true)
        {
            QTextStream stream(&file);
            stream >> start >> end >> id;
            file.close();
            flag = 1;
        }
        else
        {
            id = str + '1';
        }
        if(id == str)
        {
            file.remove("../" + filename + ".txt");
            int ret = QMessageBox::question(this,"退票","是否退票",QMessageBox::Yes|QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Yes:
                 QMessageBox::about(this,"退票","退票成功！");
                 return ;
            case QMessageBox::Cancel:
                 return;
            default:
                break;
            }

        }

    }
    if(flag == 0)files.remove("../文件名.txt");
    QMessageBox::about(this,"退票","无该乘客信息");
}
