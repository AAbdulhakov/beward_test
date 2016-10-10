#include "fifo_reader.h"

fifo_reader::fifo_reader(QObject *parent) : QObject(parent)
{
    unlink(FIFO);

    /*Создаем FIFO*/

    if((mkfifo(FIFO, O_RDWR)) == -1)

    {
        qDebug()<<"Ошибка mkfifo";

        QString mes = QString("Не удалось создать именованый канал: ")+QString(FIFO)+"проверьте настройки доступа. Дальнейшая работа невозможна";

        QMessageBox::critical(0,"Критическая ошибка",mes);

        //QCoreApplication::quit();

    }

//    unlink(FIFOw);

//    if((mkfifo(FIFOw, O_RDWR)) == -1)

//    {
//        qDebug()<<"Ошибка mkfifo FIFOw";
//        //return;

//    }



}


void fifo_reader::read_fifo() // тут читаем
{
    // qDebug()<<"read_fifo run";


    FILE *fp;
    char buf[80];








    fp = fopen(FIFO, "r");

    if(fp ==NULL)
    {
        return;
    }


    if(fgets(buf, 80, fp) == NULL)
    {
        return;
    };


    //printf("Получена строка: %s\n", buf);
    fclose(fp);

    //qDebug()<<buf;



    //QString r =  QString ("Получена строка: %s\n").arg(buf);

    QString r (buf);

    emit fifodata(r);

    QCoreApplication::processEvents();


    //emit fifodata("gfookj");

}

void fifo_reader::write_fifo(QString mes) //тут пишем
{
//    FILE *fp;

//    qDebug()<<"start";

//    if ((fp = fopen(FIFOw, "w")) == NULL)
//    {
//        qDebug()<<"fopen error";
//        return;
//    }
//    fputs(mes.toLatin1().data(), fp);
//    fclose(fp);

//    qDebug()<<"done";

}




















