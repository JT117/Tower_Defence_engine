#include <QApplication>
#include <QtGui>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <iostream>
#include "Plateau.h"

using namespace std;


int main(int argc, char *argv[])
{
    //QApplication::setGraphicsSystem("raster");
    QApplication app(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    Plateau* fenetre = new Plateau();
    fenetre->show();

    return app.exec();
}
