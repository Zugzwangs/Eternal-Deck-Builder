#include <QDebug>
#include <algorithm>
#include "game_element.h"

// /////////////////////////////////////////
// Objet modélisant une carte
Carte::Carte(QObject* parent) : QObject(parent) {}

Carte::Carte(QStringList L, QObject* parent) : QObject(parent)
{
    setCard(L);
}

Carte::~Carte() {}

void Carte::setCard(QStringList L)
{
    if ( L.count() < 19 )
        return;

    QString currentType = L[7];
    if ( currentType == "Vampire" || currentType == "Imbued" )
        {
        Kind = VtesInfo::CryptType;
        Name = L[1];
        Sets = L[2];
        ImageFile = L[3] + ".jpg";
        UrlCard = L[4];
        Expansion = L[5];
        Rarity = L[6];
        Type = L[7];
        Clan = L[8];
        Grouping = L[9];
        Capacity = L[10];
        Discipline = L[11];
        Sect = L[12];
        Title = L[13];
        Trait = L[14];
        KeyWords = L[15];
        Limitation = L[16];
        Text = L[17];
        Artist = L[18];
        Commentaires = L[19];
        }
    else
        {
        Kind = VtesInfo::LibraryType;
        Name = L[1];
        Sets = L[2];
        ImageFile = L[3] + ".jpg";
        UrlCard = L[4];
        Expansion = L[5];
        Rarity = L[6];
        Type = L[7];
        SubType = L[8];
        Clan = L[9];
        Capacity = L[10];
        Discipline = L[11];
        Sect = L[12];
        PCost = L[13];
        BCost = L[14];
        CCost = L[15];
        Title = L[16];
        Trait = L[17];
        KeyWords = L[18];
        Limitation = L[19];
        Text = L[20];
        Artist = L[21];
        Commentaires = L[22];
        }
}

void Carte::clearCard()
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


// /////////////////////////////////////////
// Objet deck
Deck::Deck(QObject *parent) : QObject(parent)
{
    DeckName.clear();
    LibrarySize = 0;
    CryptSize = 0;
}

void Deck::setupDeck()
{
    LibrarySize = Library.count();
    CryptSize = Crypt.count();
    emit deck_loaded();
}

void Deck::addCard(Carte *crt)
{
    if ( crt->getKind() == VtesInfo::LibraryType ){
        crt->setParent( this );
        Library.append(crt);}
    else
        {
        if ( crt->getKind() != VtesInfo::NoType ){
            crt->setParent( this );
            Crypt.append(crt);}
        }
}

QString Deck::getDeckName()
{
    return DeckName;
}

int Deck::getLibrarySize()
{
    return LibrarySize;
}

int Deck::getCryptSize()
{
    return CryptSize;
}

Carte* Deck::drawLib()
{
    if ( !Library.isEmpty() ){
        Hand.append( Library.takeFirst() );
        return Hand.last();
        }
    else{
        return NULL;
        }
}

Carte* Deck::drawCrypt()
{
    if ( !Crypt.isEmpty() ){
        Uncontroled.append( Crypt.takeFirst() );
        return Uncontroled.last();
        }
    else{
        return NULL;
        }
}

Carte* Deck::burnLib()
{
    if ( !Library.isEmpty() ){
        ashHeap.append( Library.takeFirst() );
        return ashHeap.last();
        }
    else{
        return NULL;
        }
}

Carte* Deck::burnCrypt()
{
    if ( !Crypt.isEmpty() ){
        ashHeap.append( Crypt.takeFirst() );
        return ashHeap.last();
        }
    else{
        return NULL;
        }
}

void Deck::library_shuffle()
{
    std::random_shuffle(Library.begin(), Library.end());
    // or maybe
    //#include <random>
    //std::random_device rd;
    //std::mt19937 rng(rd());
    //std::shuffle(Library.begin(), Library.end(), rng);
}

void Deck::crypt_shuffle()
{
    std::random_shuffle(Crypt.begin(), Crypt.end());
}

void Deck::clearDeck()
{
    DeckName.clear();
    Crypt.clear();
    Library.clear();
    ashHeap.clear();
    Hand.clear();
    Uncontroled.clear();
    Uncapacited.clear();
    Removed.clear();
    InPlay.clear();
    emit deck_cleared();
}

Deck::~Deck()
{

}

// /////////////////////////////////////////
// A player
Player::Player(QObject* parent) : QObject(parent)
{
    nickName = "Unnamed Player";
    rank = "blood bag";
    avatar = QPixmap(80,80);
    avatar.fill(Qt::black);
}

Player::~Player()
{

}




