#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>

mybutton::mybutton(QWidget *parent)
    : QPushButton{parent}
{}

void mybutton::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "left button";

        //ev->ignore();//忽略事件,事件继续传递
    }
    else
    {
    QPushButton::mousePressEvent(ev);
    }
}
