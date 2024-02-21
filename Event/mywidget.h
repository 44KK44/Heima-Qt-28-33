#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

protected:
    void keyPressEvent(QKeyEvent *ev);//键盘按下事件

    void timerEvent(QTimerEvent *ev);//定时器事件

    void mousepressevent(QMouseEvent *ev);//鼠标按下事件

    void clodeEvent(QCloseEvent *ev);//关闭事件

private:
    Ui::MyWidget *ui;

    int timerID;
    int timerID2;
};
#endif // MYWIDGET_H
