#ifndef SUBWIDGET1_H
#define SUBWIDGET1_H

#include <QWidget>
#include <QPushButton>
class subWidget1 : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget1(QWidget *parent = nullptr);
    void sendSlot1();
signals:
    void mysingal1();

public slots:
private:
    QPushButton b;
};

#endif // SUBWIDGET1_H
