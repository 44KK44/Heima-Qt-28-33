#include "mywidget.h"
#include "ui_mywidget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimerEvent>
#include <QString>
#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    timerID = this->startTimer(1000);//间隔1s
    this->timerID2 = this->startTimer(500);//间隔0.5s

    connect(ui->pushButton, &mybutton::clicked,
            [=]()
            {
                qDebug() << "按钮被按下";
            }
            );
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_A)
    {
        ui->label->setText("<center><h1>A</h1></center>");
    }
    else if (ev->key() == Qt::Key_Up)
    {
        ui->label->setText("<center><h1>Up</h1></center>");
    }
    else if (ev->key() == Qt::Key_Down)
    {
        ui->label->setText("<center><h1>Down</h1></center>");
    }
    else if (ev->key() == Qt::Key_Left)
    {
        ui->label->setText("<center><h1>Left</h1></center>");
    }
    else if (ev->key() == Qt::Key_Right)
    {
        ui->label->setText("<center><h1>Right</h1></center>");
    }
    else
    {
        ui->label->setText("<center><h1>other key</h1></center>");
    }
}

void MyWidget::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == this->timerID){
        static int sec = 0;
        // sec++;
        ui->label->setText(QString{"<center><h1>time: %1</h1></center>"}.arg(sec++));

        if(10 == sec)
        {
            this->killTimer(timerID);//停止定时器
        }
    }
    else if(ev->timerId() == this->timerID2){
        static int sec = 0;
        // sec++;
        ui->label_2->setText(QString{"<center><h1>time: %1</h1></center>"}.arg(sec++));

        if(10 == sec)
        {
            this->killTimer(timerID2);//停止定时器
        }
    }
}

void MyWidget::mousepressevent(QMouseEvent *ev)
{
    qDebug() << "6666666666";
}

void MyWidget::clodeEvent(QCloseEvent *ev)
{
    int ret = QMessageBox::question(this, "question", "是否关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        ev->accept();//接受事件
    }
    else
    {
        //忽略事件
        ev->ignore();
    }
}
