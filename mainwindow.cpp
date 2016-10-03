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


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setColor(int col)
{
   //qDebug()<<col;

   ui->led->setLEDColor((LEDColor)col);






}
