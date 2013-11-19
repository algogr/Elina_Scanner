#include "elina_scanner.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Elina_Scanner w;
    w.show();
    w.move(0,0);
    return a.exec();
}
