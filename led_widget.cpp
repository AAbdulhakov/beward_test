#include "led_widget.h"

led_widget::led_widget(QWidget *parent) : QWidget(parent)
{
    current_color_1 = QColor(245, 0, 0);
    current_color_2 = QColor(210, 0, 0);
    current_color_3 = QColor(140, 0, 0);


    color_1 = current_color_1; //текущий цвет
    color_2 = current_color_2;
    color_3 = current_color_3;

    status_on_of = true;


    currentcolor = red;
    currentrate = 0;





    timer_ = new QTimer(this);

    connect(timer_, SIGNAL(timeout()), this, SLOT(flicker()));

    //timer_->start(1000);

    blink = false;

}


led_widget::~led_widget()
{}


QString led_widget::get_led_state() //состояние светодиода
{
    if(status_on_of == true)
    {
        return "OK on";
    }
    else
    {
        return "OK off" ;
    }
}

QString led_widget::get_led_color() //свет светодиода
{
    if(currentcolor == red)
    {
        return "OK red";
    }
    if(currentcolor == green)
    {
        return "OK green";
    }
    if(currentcolor == blue)
    {
        return "OK blue";
    }
}

QString led_widget::get_led_rate() //частота мерцания
{
    return "OK "+QString::number(currentrate);
}



void led_widget::setLEDState(bool on) //включение выключние светодиода
{

    status_on_of = on;
    setprivatColor(current_color_1,current_color_2,current_color_3);

}




void led_widget::setLEDColor(LEDColor col)
{
    switch (col)
    {
    case red:
        current_color_1 = QColor(245, 0, 0);
        current_color_2 = QColor(210, 0, 0);
        current_color_3 = QColor(140, 0, 0);
        currentcolor = red;
        setprivatColor(current_color_1,current_color_2,current_color_3);
        break;
    case green:
        current_color_1 = QColor(0, 245, 0);
        current_color_2 = QColor(0, 210, 0);
        current_color_3 = QColor(0, 140, 0);
        currentcolor = green;
        setprivatColor(current_color_1,current_color_2,current_color_3);
        break;
    case blue:
        current_color_1 = QColor(0, 0, 245);
        current_color_2 = QColor(0, 0, 210);
        current_color_3 = QColor(0, 0, 140);
        currentcolor = blue;
        setprivatColor(current_color_1,current_color_2,current_color_3);
        break;


    default:
        break;
    }


    //update();


}
void led_widget::setLEDFrameRate(int rate)
{
    currentrate = rate;


    if(rate == 0 )
    {
        timer_->stop();

        color_1 = current_color_1; //что бы светодиод ври выключении мерцания горел
        color_2 = current_color_2;
        color_3 = current_color_3;
        blink = false;
        setprivatColor(current_color_1,current_color_2,current_color_3);



    }
    else
    {
        timer_->setInterval(1000/rate);
        timer_->start();
    }

}




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

        setprivatColor(color_1,color_2,color_3);



        blink = true;

    }
    else
    {
        color_1 = current_color_1;
        color_2 = current_color_2;
        color_3 = current_color_3;

        //color_1 = QColor(245, 0, 0); //красный
        //color_2 = QColor(210, 0, 0);
        //color_3 = QColor(140, 0, 0);

        setprivatColor(color_1,color_2,color_3);


        blink = false;
    }


    //update();

}


void led_widget::setprivatColor(QColor c1,QColor c2,QColor c3)
{

    if(status_on_of == true)
    {
        color_1 = c1;
        color_2 = c2;
        color_3 = c3;
    }
    else
    {
        color_1 = QColor(245, 245, 245); //серый
        color_2 = QColor(210, 210, 210);
        color_3 = QColor(140, 140, 140);
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
