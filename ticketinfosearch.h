#ifndef TICKETINFOSEARCH_H
#define TICKETINFOSEARCH_H

#include <QDialog>

namespace Ui {
class Ticketinfosearch;
}

class Ticketinfosearch : public QDialog
{
    Q_OBJECT

public:
    explicit Ticketinfosearch(QWidget *parent = 0);
    ~Ticketinfosearch();
    void sendSlot_3();
    void search();
signals:
    void Mysignal_3();
private:
    Ui::Ticketinfosearch *ui;
    QString start,end,id,name;
    int price;
};

#endif // TICKETINFOSEARCH_H
