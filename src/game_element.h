#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include <QString>
#include <QList>
#include <QPixmap>

#include "Global.h"

using namespace VtesInfo;

class Carte : public QObject
{
    Q_OBJECT
    // crypt card or library card or something else
    Q_PROPERTY(CardType Kind READ getKind)
    Q_ENUMS(CardType)
    // core data of cards
    Q_PROPERTY(QString Name READ getName)
    Q_PROPERTY(QString Sets READ getSets)
    Q_PROPERTY(QString ImageFile READ getImageFile)
    Q_PROPERTY(QString UrlCard READ getUrlCard)
    Q_PROPERTY(QString Expansion READ getExpansion)
    Q_PROPERTY(QString Rarity READ getRarity)
    Q_PROPERTY(QString Type READ getType)
    Q_PROPERTY(QString SubType READ getSubType)
    Q_PROPERTY(QString Clan READ getClan)
    Q_PROPERTY(QString Capacity READ getCapacity)
    Q_PROPERTY(QString Grouping READ getGrouping)
    Q_PROPERTY(QString Discipline READ getDiscipline)
    Q_PROPERTY(QString Sect READ getSect)
    Q_PROPERTY(QString PCost READ getPCost)
    Q_PROPERTY(QString BCost READ getBCost)
    Q_PROPERTY(QString CCost READ getCCost)
    Q_PROPERTY(QString Title READ getTitle)
    Q_PROPERTY(QString Trait READ getTrait)
    Q_PROPERTY(QString KeyWords READ getKeyWords)
    Q_PROPERTY(QString Limitation READ getLimitation)
    Q_PROPERTY(QString Text READ getText)
    Q_PROPERTY(QString Artist READ getArtist)
    Q_PROPERTY(QString Commentaires READ getCommentaires)

public:

    Carte(QObject* parent=0);                   // create an empty card
    Carte(QStringList L, QObject* parent=0);    // create and setup a card
    void setCard(QStringList L);
    void clearCard();
    virtual ~Carte();

    CardType getKind() const;
    QString getName() const;
    QString getSets() const;
    QString getImageFile() const;
    QString getUrlCard() const;
    QString getExpansion() const;
    QString getRarity() const;
    QString getType() const;
    QString getSubType() const;
    QString getClan() const;
    QString getCapacity() const;
    QString getGrouping() const;
    QString getDiscipline() const;
    QString getSect() const;
    QString getPCost() const;
    QString getBCost() const;
    QString getCCost() const;
    QString getTitle() const;
    QString getTrait() const;
    QString getKeyWords() const;
    QString getLimitation() const;
    QString getText() const;
    QString getArtist() const;
    QString getCommentaires() const;

private:
    CardType Kind;
    QString Name;
    QString Sets;
    QString ImageFile;
    QString UrlCard;
    QString Expansion;
    QString Rarity;
    QString Type;
    QString SubType;
    QString Clan;
    QString Capacity;
    QString Grouping;
    QString Discipline;
    QString Sect;
    QString PCost;
    QString BCost;
    QString CCost;
    QString Title;
    QString Trait;
    QString KeyWords;
    QString Limitation;
    QString Text;
    QString Artist;
    QString Commentaires;
};

class Deck : public QObject
{
    Q_OBJECT

public:
    Deck(QObject* parent=0);
    ~Deck();
    void addCard(Carte *crt);
    Carte* drawLib();
    void clearDeck();
    void setUpDeck();

    int Id;
    QString Nom;
    QString Auteur;
    QString Descriptif;
    QString Resultat;
    QString Date;
    QString Commentaire;
    QList<Carte *>Crypt;
    QList<Carte *>Library;
    QList<Carte *>ashHeap;

public slots:

};

#endif // GAME_ELEMENT_H
