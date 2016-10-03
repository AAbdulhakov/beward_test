#include "led_widget.h"

led_widget::led_widget(QWidget *parent) : QWidget(parent)
{
    color_1 = QColor(245, 0, 0);
    color_2 = QColor(210, 0, 0);
    color_3 = QColor(140, 0, 0);

    timer_ = new QTimer(this);

    connect(timer_, SIGNAL(timeout()), this, SLOT(flicker()));

    timer_->start(1000);

    blink = false;

}


led_widget::~led_widget()
{}

void led_widget::flicker()
{
    if(blink == false)
    {
       // color_1 = QColor(0, 245, 0);
       // color_2 = QColor(0, 210, 0);
       // color_3 = QColor(0, 140, 0);

        color_1 = QColor(245, 245, 245); //серый
        color_2 = QColor(210, 210, 210);
        color_3 = QColor(140, 140, 140);


        blink = true;

    }
    else
    {
        color_1 = QColor(245, 0, 0); //красный
        color_2 = QColor(210, 0, 0);
        color_3 = QColor(140, 0, 0);
        blink = false;
    }


    update();

}






void led_widget::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event);


    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::transparent);


    int radius = 100;




    radius -= 13;
    QLinearGradient lg2(0, -radius, 0, radius);
    lg2.setColorAt(0, QColor(155, 155, 155));
    lg2.setColorAt(1, QColor(255, 255, 255));
    painter.setBrush(lg2);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);



    //Внутренние круги
    radius -= 4;
    QRadialGradient rg(0, 0, radius);
    rg.setColorAt(0, color_1);
    rg.setColorAt(0.6, color_2);
    rg.setColorAt(1, color_3);
    painter.setBrush(rg);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);


}
