#include "led_widget.h"

led_widget::led_widget(QWidget *parent) : QWidget(parent)
{

}


led_widget::~led_widget()
{}

void led_widget::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event);
    /*
    QPainter p(this);

    QRadialGradient g(0, 0, 100,100,100,100);

    QBrush brush(g);



    QColor color_(QColor("red"));


    int radius = 100;

    QLinearGradient lg1(0, -radius, 0, radius);
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(166, 166, 166));
    p.setBrush(lg1);
    p.drawEllipse(-radius, -radius, radius << 1, radius << 1);


   // p.setPen(color_);
    //p.setRenderHint(QPainter::Antialiasing, true);
   // p.setBrush(brush);
   // p.drawEllipse(0, 0, 100, 100);

*/

    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::transparent);
    //painter.fillRect(-width(), -height(), width() * 2, height() * 2, Qt::gray);

    int radius = 100;

/*
    QLinearGradient lg1(0, -radius, 0, radius);
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(166, 166, 166));
    painter.setBrush(lg1);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

*/


    radius -= 13;
    QLinearGradient lg2(0, -radius, 0, radius);
    lg2.setColorAt(0, QColor(155, 155, 155));
    lg2.setColorAt(1, QColor(255, 255, 255));
    painter.setBrush(lg2);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);



    //Внутренние круги
    radius -= 4;
    QRadialGradient rg(0, 0, radius);
    rg.setColorAt(0, QColor(245, 0, 0));
    rg.setColorAt(0.6, QColor(210, 0, 0));
    rg.setColorAt(1, QColor(140, 0, 0));
    painter.setBrush(rg);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    /*
    radius -= 3;
    QPainterPath path;
    path.addEllipse(-radius, -radius - 2, radius << 1, radius << 1);
    QPainterPath bigEllipse;
    radius *= 2;
    bigEllipse.addEllipse(-radius, -radius + 140, radius << 1, radius << 1);
    path -= bigEllipse;



    QLinearGradient lg3(0, -radius / 2, 0, 0);
    lg3.setColorAt(0, QColor(255, 255, 255, 220));
    lg3.setColorAt(1, QColor(255, 255, 255, 30));
    painter.setBrush(lg3);
    painter.drawPath(path);

*/

}
