#ifndef LED_WIDGET_H
#define LED_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

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


private slots:
    void flicker();

private:
    QColor color_1;
    QColor color_2;
    QColor color_3;

    QTimer* timer_;

    bool blink;

};

#endif // LED_WIDGET_H
