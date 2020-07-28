#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QLocale"
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Перевод приложения на другие языки
    QTranslator translator;
    translator.load("tns_" + QLocale::system().name());  //
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
