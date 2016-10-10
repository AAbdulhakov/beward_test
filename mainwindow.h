#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QDebug>
#include <QThread>

#include "fifo_reader.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setColor(int col);

    void Message(QString m);

    void Server_body(QString m); //обработка протокола




    void on_pushButton_clicked();

signals:
    void read_fifo();
    void write_fifo(QString m); //ответ на команду


private:
    Ui::MainWindow *ui;
    QButtonGroup *buttons;


    QString Parser(QString m); //парсер команд
    QString Parser1command(QString m); //парсер команд без аргументов
    QString Parser2command(QString m1, QString m2); //парсер команд c аргументами



};

#endif // MAINWINDOW_H
