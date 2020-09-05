#ifndef SUBWIDGET2_H
#define SUBWIDGET2_H

#include <QWidget>
#include <QPushButton>
class subWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget2(QWidget *parent = nullptr);
    void sendSlot2();
signals:
    void mysingal2();

public slots:
private:
    QPushButton b;
};

#endif // SUBWIDGET2_H
