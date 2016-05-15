/* Module contenant les caracteristiques de Jyhad */
#include "Global.h"

#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>

PathProvider::PathProvider()
{
    CardPath = "";
    DeckPath = "";
}

bool PathProvider::initPaths()
{

int i=0;
bool flag = false;
QDir AppFolder;

    AppFolder.setPath(QCoreApplication::applicationDirPath());
    while (AppFolder.dirName() != "bin" && i<4)
        {
        i++;
        AppFolder.cdUp();
        }

    AppFolder.cdUp();
    if (AppFolder.cd("Cartes"))
        {
        CardPath = AppFolder.absolutePath();
        flag = true;
        }

    AppFolder.cdUp();
    if (AppFolder.cd("Decks"))
        {
        DeckPath = AppFolder.absolutePath();
        }
    else
        flag = false;

    return flag;
}

QString PathProvider::getCardPath()
{
    return CardPath;
}

QString PathProvider::getDeckPath()
{
    return DeckPath;
}
