#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QString>

#include "Global.h"
#include "mvddeck.h"

/************************************************************************************/
/*    */
/*    */
/************************************************************************************/

bool deckModelToEdb(PTreeModel *D, QString filePath);

bool EdbToDeckModel(PTreeModel *D, QString filePath);

bool deckModelToPDF(PTreeModel *D, QString filePath);

#endif // SAUVEGARDE_H
