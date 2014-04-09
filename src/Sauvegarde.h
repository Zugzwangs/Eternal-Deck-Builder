#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QString>

#include "game_element.h"

/************************************************************************************************************/
/* Contient les routines necessaires � faire la conversion entre les diff�rentes representation d'un Deck   */
/*     - fichier XML <==> Objet de la Class 'Deck'                                                          */
/*     - fichier TXT <==> Objet de la Class 'Deck'                                                          */
/*     - Mod�le de donn�es <==> Objet de la Class 'Deck'                                                    */
/*                                                                                                          */
/* Toutes les fonctions retournent un Bool�en pour dire si la proc�dure � r�ussie                           */
/************************************************************************************************************/

bool Deck2Xml(Deck &D , QString filePath);

/*
VtesInfo::Deck Xml2Deck(QString PathXMLFileDeck);
bool Deck2TXT(VtesInfo::Deck D, QString fileName);
VtesInfo::Deck TXT2Deck(QString PathXMLFileDeck);
*/
#endif // SAUVEGARDE_H
