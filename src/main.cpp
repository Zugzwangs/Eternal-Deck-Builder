#include <QtWidgets>
#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon( QIcon(":/icons/logo_edb.png") );
    MainWindow w;
    w.show();
    
    return a.exec();
}
