#include "game_element.h"

// /////////////////////////////////////////
// Objet modélisant une carte
Carte::Carte(QObject* parent) : QObject(parent)
{
}

Carte::Carte(const Carte &c) //: QObject(c)
{
}

Carte::Carte(QString s)
{

}
Carte::Carte(QStringList)
{
}

CardType Carte::getKind() const { return(Kind); }
QString Carte::getName() const { return(Name); }
QString Carte::getSets() const { return(Sets); }
QString Carte::getImageFile() const { return(ImageFile); }
QString Carte::getUrlCard() const { return(UrlCard); }
QString Carte::getExpansion() const { return(Expansion); }
QString Carte::getRarity() const { return(Rarity); }
QString Carte::getType() const { return(Type); }
QString Carte::getSubType() const { return(SubType); }
QString Carte::getClan() const { return(Clan); }
QString Carte::getCapacity() const { return(Capacity); }
QString Carte::getGrouping() const { return(Grouping); }
QString Carte::getDiscipline() const { return(Discipline); }
QString Carte::getSect() const { return(Sect); }
QString Carte::getPCost() const { return(PCost); }
QString Carte::getBCost() const { return(BCost); }
QString Carte::getCCost() const { return(CCost); }
QString Carte::getTitle() const { return(Title); }
QString Carte::getTrait() const { return(Trait); }
QString Carte::getKeyWords() const { return(KeyWords); }
QString Carte::getLimitation() const { return(Limitation); }
QString Carte::getText() const { return(Text); }
QString Carte::getArtist() const { return(Artist); }
QString Carte::getCommentaires() const { return(Commentaires); }

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
