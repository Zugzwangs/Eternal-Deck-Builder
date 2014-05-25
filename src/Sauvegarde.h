#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QString>

#include "Global.h"
#include "mvddeck.h"
#include "mvdbdd.h"

/************************************************************************************/
/*    */
/*    */
/************************************************************************************/

class DeckTranslator
{

public:
    DeckTranslator();
    DeckTranslator(PTreeModel* DeckModel, QSqlQueryModel* BddModel);
    void setDeckModel(PTreeModel* DeckModel);
    void setBddModel(QSqlQueryModel* BddModel);

public slots:
    bool deckModelToEdb( QString filePath );
    bool EdbToDeckModel( QString filePath );
    bool deckModelToPDF( QString filePath );
    QStringList queryCardsInfo( const QString CardName, const QString TableName );

private:
    PTreeModel* D;
    QSqlQueryModel* B;
};

#endif // SAUVEGARDE_H
