#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->checkBox_onoff->setVisible(false);


    buttons = new QButtonGroup(this);

    buttons->addButton(ui->radioButton_red,0);
    buttons->addButton(ui->radioButton_green,1);
    buttons->addButton(ui->radioButton_blue,2);

    connect(buttons,SIGNAL(buttonClicked(int)),this,SLOT(setColor(int)));


    connect(ui->horizontalSlider_rate,SIGNAL(valueChanged(int)),ui->led,SLOT(setLEDFrameRate(int)));
    connect(ui->checkBox_onoff,SIGNAL(clicked(bool)),ui->led,SLOT(setLEDState(bool)));

    fifo_reader *fifo_read = new fifo_reader();


    QThread *tread1 = new QThread;

    fifo_read->moveToThread(tread1);

    connect(fifo_read,SIGNAL(fifodata(QString)),this,SLOT(Server_body(QString)));
    connect(this,SIGNAL(read_fifo()),fifo_read,SLOT(read_fifo()));

    connect(this,SIGNAL(write_fifo(QString)),fifo_read,SLOT(write_fifo(QString)));


    tread1->start();

    emit read_fifo();




}

MainWindow::~MainWindow()
{
    delete ui;
    //delete tread1;

}


void MainWindow::Server_body(QString m) //обработка протокола
{

    Message("R: "+m);
    //================ Парсер команд ==================

    Message("A: " +Parser(m)); //парсер команд

    //=================================================




    emit write_fifo("OK"); //отправим ответ

    emit read_fifo(); //закольцуем

}


QString MainWindow::Parser(QString m) //парсер команд
{
    QString com = m.simplified();

    QStringList commstr = com.split(" ");

    if(commstr.size() == 1) //если команды без аргументов
    {
        return Parser1command(commstr.at(0));
    }
    else if(commstr.size() == 2)//если команды c аргументами
    {
        return Parser2command(commstr.at(0),commstr.at(1));
    }
    else
    {
        return "FAILED";
    }


}

QString MainWindow::Parser1command(QString m) //парсер команд без аргументов
{
    if(m =="get-led-state")
    {
        return (ui->led->get_led_state());
    }

    if(m =="get-led-color")
    {
        return ("OK "+ui->led->get_led_color());
    }

    if(m =="get-led-rate")
    {
        return ("OK "+ui->led->get_led_rate());
    }

    //get-led-color
    //get-led-rate

    return "FAILED";

}

QString MainWindow::Parser2command(QString m1,QString m2) //парсер команд c аргументами
{

    if(m1 =="set-led-state")
    {
        if(m2 == "on")
        {
            ui->led->setLEDState(true);
            return "OK";
        }
        if(m2 == "off")
        {
            ui->led->setLEDState(false);
            return "OK";
        }

        return "FAILED";
    }

    if(m1 =="set-led-color")
    {
        if(m2 == "red")
        {
            ui->led->setLEDColor(red);
            return "OK";
        }
        if(m2 == "green")
        {
            ui->led->setLEDColor(green);
            return "OK";
        }
        if(m2 == "blue")
        {
            ui->led->setLEDColor(blue);
            return "OK";
        }
        return "FAILED";
    }


    if(m1 =="set-led-rate")
    {
        bool ok;
        int rate = m2.toInt(&ok,10);

        if(ok == false)
        {
            return "FAILED";
        }

        if(rate >=0 && rate <=5)
        {
            ui->led->setLEDFrameRate(rate);
            return "OK";
        }

        return "FAILED";

    }


    return "FAILED";
}





void MainWindow::Message(QString m)
{
    ui->textEdit->append(m);

}







void MainWindow::setColor(int col)
{
    //qDebug()<<col;

    ui->led->setLEDColor((LEDColor)col);

}

void MainWindow::on_pushButton_clicked()
{
    emit  read_fifo();
}
