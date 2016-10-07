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

    void on_pushButton_clicked();

signals:
    void read_fifo();

private:
    Ui::MainWindow *ui;
    QButtonGroup *buttons;
};

#endif // MAINWINDOW_H
