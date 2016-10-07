#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    connect(fifo_read,SIGNAL(fifodata(QString)),this,SLOT(Message(QString)));
    connect(this,SIGNAL(read_fifo()),fifo_read,SLOT(read_fifo()));

    tread1->start();

    emit read_fifo();




}

MainWindow::~MainWindow()
{
    delete ui;
    //delete tread1;

}


void MainWindow::Message(QString m)
{
    ui->textEdit->append(m);

    emit  read_fifo(); //закольцуем




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
