#include "ticketsearch.h"
#include "ui_ticketsearch.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QTextStream>
Ticketsearch::Ticketsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ticketsearch)
{
    ui->setupUi(this);
    setWindowTitle("余票查询窗口");
    connect(ui->pushButton_back,&QPushButton::clicked,this,&Ticketsearch::sendSlot_1);
    //ui->label_price->hide();
    //ui->label_remains->hide();
    ui->label_num1->hide();
    ui->label_num2->hide();
    connect(ui->pushButton_yes,&QPushButton::clicked,this,&Ticketsearch::count);
}

Ticketsearch::~Ticketsearch()
{
    delete ui;
}
void Ticketsearch::sendSlot_1()
{
    emit Mysignal_1();
    //ui->label_num1->setText("");
    //ui->label_num2->setText("");
    ui->comboBox_end->setCurrentText("A2");
    ui->comboBox_start->setCurrentText("A1");
    ui->label_num1->hide();
    ui->label_num2->hide();

}
void Ticketsearch::count()
{

    int sum = 10;
    QString s1,s2;
    QString s3 = ui->comboBox_start->currentText();
    QString s4 = ui->comboBox_end->currentText();
    if(s3 >= s4&&s4 != "A10")
    {
        QMessageBox::about(this,"车站信息","车站行程不存在,请重新选择！");
        return;
    }
    QFile files("../文件名.txt");
    QString filename1;
    QString filename = "passenger.info";
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
        QFile file("../" + filename +".txt");
        isok = file.open(QIODevice::ReadOnly);
        if(isok == true)
        {
            QTextStream stream(&file);
            stream >> s1 >>s2;
            file.close();
        }
        if(!(s3 >= s2|| s4 <= s1))sum--;

    }
    if(sum <= 0)
    {
        sum = 0;

    }
    QString str1 = QString("%1").arg(sum) + "张";
    ui->label_num1->setText(str1);
    int price = 0;
    int i = 0;
    while(i<9)
    {
        if(s3 <=station[i]&&s4 >station[i])price += array[i];
        else if(s4 == "A10"&&s3 <= station[i])price += array[i];
        i++;
    }
    QString str2 = QString("%1").arg(price) + "元";
    ui->label_num2->setText(str2);
    ui->label_num1->show();
    ui->label_num2->show();
    if(sum == 0)
    {
        QMessageBox::information(this,"余票查询","当前车站余票为零，请选择其它车站");
    }
}
