#include "game_element.h"

// /////////////////////////////////////////
// Objet modélisant une carte
Carte::Carte(QObject* parent) : QObject(parent)
{
}

Carte::Carte(const Carte &c)
{
}

Carte::Carte(QString s)
{

}
Carte::Carte(QStringList)
{
}

CardType Carte::getKind() const {}
QString Carte::getName() const {}
QString Carte::getSets() const {}
QString Carte::getImageFile() const {}
QString Carte::getUrlCard() const {}
QString Carte::getExpansion() const {}
QString Carte::getRarity() const {}
QString Carte::getType() const {}
QString Carte::getSubType() const {}
QString Carte::getClan() const {}
QString Carte::getCapacity() const {}
QString Carte::getGrouping() const {}
QString Carte::getDiscipline() const {}
QString Carte::getSect() const {}
QString Carte::getPCost() const {}
QString Carte::getBCost() const {}
QString Carte::getCCost() const {}
QString Carte::getTitle() const {}
QString Carte::getTrait() const {}
QString Carte::getKeyWords() const {}
QString Carte::getLimitation() const {}
QString Carte::getText() const {}
QString Carte::getArtist() const {}
QString Carte::getCommentaires() const {}

Carte::~Carte()
{

}

void Carte::SetCard(QStringList L)
{

}

void Carte::ClearCard()
{

}


// /////////////////////////////////////////
// Objet deck
Deck::Deck()
{

}

void Deck::AddCard(Carte crt)
{

}

void Deck::RemoveCard(QString cardName, bool all)
{
}
