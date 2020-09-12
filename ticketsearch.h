#ifndef TICKETSEARCH_H
#define TICKETSEARCH_H

#include <QDialog>

namespace Ui {
class Ticketsearch;
}

class Ticketsearch : public QDialog
{
    Q_OBJECT

public:
    explicit Ticketsearch(QWidget *parent = 0);
    ~Ticketsearch();
    void sendSlot_1();
    void count();
signals:
    void Mysignal_1();
private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Ticketsearch *ui;
    //int sum = 10;
    QString station[10]={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10"};
    int array[9]={1,2,3,4,5,6,7,8,9};
};

#endif // TICKETSEARCH_H
