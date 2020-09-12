#ifndef TICKETBUY_H
#define TICKETBUY_H

#include <QDialog>

namespace Ui {
class TicketBuy;
}

class TicketBuy : public QDialog
{
    Q_OBJECT

public:
    explicit TicketBuy(QWidget *parent = 0);
    ~TicketBuy();
    void sendSlot_2();
    void save();
signals:
    void Mysignal_2();
private:
    Ui::TicketBuy *ui;
    QString start,end,id,name,phone;
    int array[10] = {1,2,3,4,5,6,7,8,9};//价格
    QString station[10] ={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10"};
};

#endif // TICKETBUY_H
