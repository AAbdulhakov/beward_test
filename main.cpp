#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>



int main(int argc, char *argv[])
{

    QTextCodec *cyrillicCodec = QTextCodec::codecForName("UTF-8");
   // QTextCodec::setCodecForLocale(ForTr(cyrillicCodec);
    QTextCodec::setCodecForLocale(cyrillicCodec);
   // QTextCodec::setCodecForCStrings(cyrillicCodec);




    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
