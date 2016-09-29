#ifndef LED_WIDGET_H
#define LED_WIDGET_H

#include <QWidget>
#include <QPainter>

class led_widget : public QWidget
{
    Q_OBJECT
public:
    explicit led_widget(QWidget *parent = 0);
    ~led_widget();

protected:
    void paintEvent(QPaintEvent* event);



signals:

public slots:





};

#endif // LED_WIDGET_H
