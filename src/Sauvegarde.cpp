#include "Sauvegarde.h"
#include "math.h"

#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QSettings>
#include <QPainter>
#include <QPrinter>
#include <QSqlQuery>

FFFF::FFFF()
{
   D = NULL;
   B = NULL;
}

FFFF::FFFF(PTreeModel* DeckModel, QSqlQueryModel* BddModel)
{
    D = DeckModel;
    B = BddModel;
}

void FFFF::setDeckModel(PTreeModel* DeckModel)
{
    D = DeckModel;
}

void FFFF::setBddModel(QSqlQueryModel *BddModel)
{
    B = BddModel;
}

QStringList FFFF::queryCardsInfo( const QString CardName, const QString TableName )
{
    QStringList infos = QStringList();
    QSqlQuery myQuery;
    myQuery.prepare( "SELECT * FROM " + TableName + " WHERE Name = :CardName" );
    myQuery.bindValue(":CardName", CardName);
    myQuery.exec();
    B->setQuery( myQuery );
    //
    if ( B->lastError().isValid())
        {
        qDebug() << "query for card " << CardName;
        qDebug() << "an error as occured during SQL query" << endl << B->lastError();
        return infos;
        }

    if ( B->record(0).isEmpty() )
        {
        return infos; //card not found
        }
    else
        {
        for (int i=0; i<(B->record(0)).count(); i++)
            {
            infos.append( B->record(0).value(i).toString() );
            }
        }

    return infos;
}

bool FFFF::deckModelToEdb( QString filePath )
{
    // open file in write mode and put the xml stream on it
    QFile file(filePath);
    if ( !file.open(QFile::WriteOnly | QFile::Text) )
        return false;

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true);             //Permet l'indentation du fichier XML
    writer.writeStartDocument();                // Écrit l'en-tête du fichier XML : <?xml version="1.0" encoding="UTF-8" ?>
    writer.writeStartElement("Deck");           // Ajoute l'élément racine du fichier XML
    writer.writeAttribute("Id","123534");       //

        /********** Elements Métadonnées **********/
        writer.writeStartElement("Metadatas");
            QMap<QString, QString>::const_iterator i;
            for (i = D->meta_list.constBegin(); i != D->meta_list.constEnd(); i++)
                {
                writer.writeStartElement("Metadata");
                writer.writeAttribute("name", i.key());
                writer.writeAttribute("value", i.value());
                writer.writeEndElement();
                }
        writer.writeEndElement();

        /**********   Element Crypte    **********/
        writer.writeStartElement("Crypt");
        writer.writeAttribute( "Taille", D->itemCrypt->data(VtesInfo::ExemplairRole).toString() );
        for ( int i=0; i<D->itemCrypt->rowCount(); i++ )
            {
            writer.writeStartElement( "CryptCard" );
            writer.writeAttribute( "Number", D->itemCrypt->child(i,0)->data(VtesInfo::ExemplairRole).toString() );
            writer.writeAttribute( "name", D->itemCrypt->child(i,0)->data(VtesInfo::NameRole).toString() );
            writer.writeEndElement();
            }
        writer.writeEndElement();

        /********** Element Bibliotheque **********/
        writer.writeStartElement("Bibliotheque");
            writer.writeAttribute( "Taille", D->itemLib->data(VtesInfo::ExemplairRole).toString() );
            for ( int i=0; i<D->itemLib->rowCount(); i++ )
                {
                writer.writeStartElement( "LibraryCard" );
                writer.writeAttribute( "Number", D->itemLib->child(i,0)->data(VtesInfo::ExemplairRole).toString() );
                writer.writeAttribute( "name", D->itemLib->child(i,0)->data(VtesInfo::NameRole).toString() );
                writer.writeEndElement();
                }
        writer.writeEndElement();                   // Ferme l'élément Bibliotheque

    writer.writeEndElement();
    writer.writeEndDocument();  // Finalise le document XML
    file.close();               // Fermer le fichier pour bien enregistrer le document et ferme l'élément Deck (l'élément Root)

    D->setUnmodified();
    return true;
}

bool FFFF::EdbToDeckModel( QString filePath )
{
    // open file in read mode and put the xml stream on it
    QFile file(filePath);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "An error has been encounter when opening deck file";
        return false;
    }

    QXmlStreamReader reader(&file);

    // read file until reach of <Metadonnees> element
    while (!reader.atEnd() && reader.name() != "Metadatas" ) {
        reader.readNext();
    }
    if (reader.hasError()) {
        qDebug() << "An error has been encounter when parsing deck file";
        qDebug() << reader.errorString() << reader.lineNumber() << reader.columnNumber();
        return false;
        }
    reader.readNextStartElement();

    while (!reader.atEnd() && reader.name() != "Metadatas" )
        {
        if ( reader.isStartElement() )
            { // marche pas ici !
            D->setMeta(reader.attributes().value("name").toString(), reader.attributes().value("value").toString());
            }
        reader.readNextStartElement();
        }
    reader.readNextStartElement();
    reader.readNextStartElement();

    while (!reader.atEnd() && reader.name() != "Crypt" )
        {
        if ( reader.isStartElement() )
            {
            D->AddCardItem( queryCardsInfo(reader.attributes().value("name").toString(), "VampireList"), reader.attributes().value("Number").toInt() );
            }
        reader.readNextStartElement();
        }
    reader.readNextStartElement();
    reader.readNextStartElement();

    while (!reader.atEnd() && reader.name() != "Bibliotheque" )
        {
        if ( reader.isStartElement() )
            {
            D->AddCardItem( queryCardsInfo(reader.attributes().value("name").toString(), "CardList"), reader.attributes().value("Number").toInt() );
            }
        reader.readNextStartElement();
        }

    return true;
}

bool FFFF::deckModelToPDF( QString filePath )
{
int NbEx;
PathProvider path_list;
path_list.initPaths();
QString CardPath = path_list.getCardPath();
QList<QString> ListPathImageCarte;

// Gathering all datas to print

//On crée la liste de tous les chemins vers les images necesaires
for (int i=0; i<D->itemCrypt->rowCount(); i++)
    {
    NbEx = D->itemCrypt->child(i,0)->data(VtesInfo::ExemplairRole).toInt();
    for (int j=1; j<=NbEx; j++)
        {
        ListPathImageCarte.append(CardPath + "/" + D->itemCrypt->child(i,0)->data(VtesInfo::ImageFileRole).toString() + ".jpg");
        }
    }
for (int i=0; i<D->itemLib->rowCount(); i++)
    {
    NbEx = D->itemLib->child(i,0)->data(VtesInfo::ExemplairRole).toInt();
    for (int j=1; j<=NbEx; j++)
        {
        ListPathImageCarte.append(CardPath + "/" + D->itemLib->child(i,0)->data(VtesInfo::ImageFileRole).toString() + ".jpg");
        }
    }

// Get print options.
QString PrintFormat;
QSettings settings("./cfg.ini", QSettings::IniFormat);
PrintFormat = settings.value("PrintFormat", "A4").toString();

// Paint procedure :
int NbPage,k,x,y;
float NbCarteParPage;
QList<QImage *> Planches;
QPainter PlanchePainter;

if (PrintFormat == "A4")
   {
    NbCarteParPage = 8;
    //En fonction du nombre de carte trouvées, on détermine le nombre de planches nécessaires
    NbPage = ceil(ListPathImageCarte.count()/NbCarteParPage);
    //On construit les planches
    for (int i=1; i<=NbPage; i++)
        {
        Planches.append(new QImage(1440,1000,QImage::Format_RGB666));
        PlanchePainter.begin(Planches.at(i-1));
        for(int j=(i-1)*NbCarteParPage; (j<=(i*NbCarteParPage)-1) && (j<ListPathImageCarte.count()); j++)
            {
            k = j-((i-1)*NbCarteParPage)+1;
            x = (k-1)%4;
            y = ceil(k/4.0)-1;
            QPixmap CarteCourante(ListPathImageCarte.at(j));
            PlanchePainter.drawPixmap(x*360,y*500,CarteCourante);
            }
        PlanchePainter.end();
        }
    }
else
   {
    NbCarteParPage = 18;
    //En fonction du nombre de carte trouvées, on détermine le nombre de planches nécessaires
    NbPage = ceil(ListPathImageCarte.count()/NbCarteParPage);
    //On construit les planches
    for (int i=1; i<=NbPage; i++)
        {
        Planches.append(new QImage(2160,1500,QImage::Format_RGB666));
        PlanchePainter.begin(Planches.at(i-1));
        for(int j=(i-1)*NbCarteParPage; (j<=(i*NbCarteParPage)-1) && (j<ListPathImageCarte.count()); j++)
            {
            k = j-((i-1)*NbCarteParPage)+1;
            x = (k-1)%6;
            y = ceil(k/6.0)-1;
            QPixmap CarteCourante(ListPathImageCarte.at(j));
            PlanchePainter.drawPixmap(x*360,y*500,CarteCourante);
            }
        PlanchePainter.end();
        }
    }

    //On crée la page de garde et on l'imprime:
    //QString html;
    //QWebView webView;
    //webView.setHtml(html);
    //webView.print(&printer);

    //Maitenant on imprime les planches que l'on a créé :
    QPrinter DeckPrinter(QPrinter::ScreenResolution);
    QPainter PrintPainter;

    DeckPrinter.setOrientation(QPrinter::Landscape);
    if ( PrintFormat == "A4" )
        DeckPrinter.setPaperSize(QPrinter::A4);
    else
        DeckPrinter.setPaperSize(QPrinter::A3);
    DeckPrinter.setOutputFormat(QPrinter::PdfFormat);
    DeckPrinter.setOutputFileName( filePath );
    DeckPrinter.setPageMargins(10,10,0,0,QPrinter::Millimeter);
    DeckPrinter.setResolution(150);

    PrintPainter.begin(&DeckPrinter);
    for(int i=0; i<Planches.count(); i++)
        {
        PrintPainter.drawImage( QPoint(0,0), *Planches.at(i) );
        DeckPrinter.newPage();
        }
    PrintPainter.end();

    return true;
}
