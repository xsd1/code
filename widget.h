#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ticketsearch.h"
#include "ticketbuy.h"
#include "ticketinfosearch.h"
#include "returnticket.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealSlot_1();
    void dealSlot_2();
    void dealSlot_3();
    void dealSlot_4();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    Ticketsearch ts;
    TicketBuy tb;
    Ticketinfosearch tfs;
    Returnticket rt;
};

#endif // WIDGET_H
