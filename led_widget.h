#ifndef LED_WIDGET_H
#define LED_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QDebug>


enum LEDColor{red = 0,green = 1, blue = 2};


class led_widget : public QWidget
{
    Q_OBJECT
public:
    explicit led_widget(QWidget *parent = 0);
    ~led_widget();

    QString get_led_state(); //состояние светодиода
    QString get_led_color(); //цвет светодиода
    QString get_led_rate(); //частота мерцания






protected:
    void paintEvent(QPaintEvent* event);



signals:




public slots:


    void setLEDState(bool on); //включение выключние светодиода
    void setLEDColor(LEDColor col);
    void setLEDFrameRate(int rate);





private slots:
    void flicker();

private:
    QColor color_1; //вспомогательные переменные
    QColor color_2;
    QColor color_3;


    QColor current_color_1; //текущий цвет
    QColor current_color_2;
    QColor current_color_3;

    void setprivatColor(QColor c1,QColor c2,QColor c3); //перерисовать светодиод с этим светом


    QTimer* timer_;

    bool blink;


    bool status_on_of;
    LEDColor currentcolor;
    int currentrate;

};

#endif // LED_WIDGET_H
