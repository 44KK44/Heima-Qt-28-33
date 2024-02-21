#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>
#include <QMouseEvent>

class Mylable : public QLabel
{
    Q_OBJECT
public:
    explicit Mylable(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *ev);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *ev);//鼠标释放事件
    void mouseMoveEvent(QMouseEvent *ev);//鼠标移动事件
    void enterEvent(QEvent *event);//鼠标进入事件
    void leaveEvent(QEvent *event);//鼠标离开事件

signals:
};

#endif // MYLABLE_H
