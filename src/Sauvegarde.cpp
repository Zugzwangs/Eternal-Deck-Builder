#include "Sauvegarde.h"
#include "game_element.h"

bool Deck2Xml(Deck & D, QString filePath)
{

QFile file(filePath);
file.open(QFile::WriteOnly | QFile::Text);
QXmlStreamWriter writer(&file);

writer.setAutoFormatting(true);                        //Permet l'indentation du fichier XML
writer.writeStartDocument();                           // Écrit l'en-tête du fichier XML : <?xml version="1.0" encoding="UTF-8" ?>
writer.writeStartElement("Deck");                      // Ajoute l'élément racine du fichier XML
writer.writeAttribute("Id","123534");                  //

/********** Elements Métadonnées **********/
writer.writeStartElement("Metadonnees");                // Ajoute l'élément Metadonnees
writer.writeTextElement("Nom", D.Nom);                  // M
writer.writeTextElement("Auteur", D.Auteur);            // E
writer.writeTextElement("Descriptif", D.Commentaire);   // T
writer.writeTextElement("Resultat", D.Resultat);        // A
writer.writeTextElement("Date", D.Date);                //
writer.writeEndElement();                               // Ferme l'élément Metadonnees

/**********   Element Crypte    **********/
writer.writeStartElement("Crypt");
writer.writeAttribute( "Taille", QString::number(D.Crypt.length()) );                  // Ajoute un attribut a l'élément Crypt
for (int i=0; i<D.Crypt.length(); i++)
    {
    //writer.writeTextElement("CryptCard", D.Crypt.at(i)->Name()); // Ajoute un element CryptCard et le ferme
    }
writer.writeEndElement();                              // Ferme l'élément Crypt

/********** Element Bibliotheque **********/
writer.writeStartElement("Bibliotheque");
writer.writeAttribute( "Taille", QString::number(D.Bibliotheque.length()) );                  // Ajoute un attribut a l'élément Crypt
for (int i=0; i<D.Bibliotheque.length(); i++)
    {
    //writer.writeTextElement("MinionCard", D.Bibliotheque.at(i)->Name); // Ajoute un element MinionCard et le ferme
    }
writer.writeEndElement();                              // Ferme l'élément Bibliotheque

writer.writeEndDocument();  // Finalise le document XML
file.close();               // Fermer le fichier pour bien enregistrer le document et ferme l'élément Deck (l'élément Root)

return true;
}


/*
Deck Xml2Deck(QString PathXMLFileDeck)
{
VtesInfo::Deck D;
return D;
}


bool Deck2TXT(Deck D, QString fileName)
{
    return true;
}

Deck TXT2Deck(QString PathXMLFileDeck)
{
}
*/
