#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *ev);//鼠标按下事件

signals:
};

#endif // MYBUTTON_H
