#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <subwidget1.h>
class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(QWidget *parent = nullptr);
    void sendSlot();
    void changewin();
    void dealsub1();
signals:
    void mysingal();

public slots:
private:
    QPushButton b1;
    QPushButton b2;
    subWidget1 w1;
};

#endif // SUBWIDGET_H
