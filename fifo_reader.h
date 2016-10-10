#ifndef FIFO_READER_H
#define FIFO_READER_H

#include <QObject>
#include <QDebug>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>
#include <fcntl.h>
#include <QCoreApplication>

#include <QMessageBox>

//#define FIFO       "/tmp/fifo0001.1"
#define FIFO       "/tmp/fifo1"
#define FIFOw       "/tmp/fifow"


class fifo_reader : public QObject
{

    Q_OBJECT

public:
    explicit fifo_reader(QObject *parent = 0);


public slots:

    void read_fifo(); // тут читаем
    void write_fifo(QString mes); //тут пишем


signals:
    void fifodata(QString mess);//тут отправляем






};

#endif // FIFO_READER_H
