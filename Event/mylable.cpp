#include "mylable.h"
#include <QMouseEvent>
#include <QDebug.h>
#include <QString>

Mylable::Mylable(QWidget *parent)
    : QLabel{parent}
{
    this->setMouseTracking(true);

}

void Mylable::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();

    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "left button";
    }
    else if (ev->button() == Qt::RightButton)
    {
        qDebug() << "right button";
    }
    else if (ev->button() == Qt::MiddleButton)
    {
        qDebug() << "middle button";
    }
    else
    {
        qDebug() << "other button";
    }

    QString text = QString{"<center><h1>mouse press"
                           ":[x: %1, y: %2]</h1></center>"}.arg(i).arg(j);

    this->setText(text);
}

void Mylable::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString{"<center><h1>mouse release"
                           ":[x: %1, y: %2]</h1></center>"}.arg(ev->x()).arg(ev->y());

    this->setText(text);
}

void Mylable::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString{"<center><h1>mouse move"
                           ":[x: %1, y: %2]</h1></center>"}.arg(ev->x()).arg(ev->y());

    this->setText(text);
}

void Mylable::enterEvent(QEvent *event)
{
    this->setText("<center><h1>mouse enter</h1></center>");
}

void Mylable::leaveEvent(QEvent *event)
{
    this->setText("<center><h1>mouse leave</h1></center>");
}
