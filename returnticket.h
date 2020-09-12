#ifndef RETURNTICKET_H
#define RETURNTICKET_H

#include <QDialog>

namespace Ui {
class Returnticket;
}

class Returnticket : public QDialog
{
    Q_OBJECT

public:
    explicit Returnticket(QWidget *parent = 0);
    ~Returnticket();
    void sendSlot_4();
    void ticketreturn();
signals:
    void Mysignal_4();
private:
    Ui::Returnticket *ui;
    QString start, end, id;
};

#endif // RETURNTICKET_H
