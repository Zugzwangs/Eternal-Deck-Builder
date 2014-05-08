#ifndef TAB_SEARCH_CRYPT_H
#define TAB_SEARCH_CRYPT_H

#include <QScrollArea>
#include <QCompleter>

#include "Global.h"
#include "mvdbdd.h"
#include "mvddeck.h"

namespace Ui {
class tab_search_crypt;
}

class tab_search_crypt : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_search_crypt(QWidget *parent = 0);
    ~tab_search_crypt();
    PSqlTableModel *ModelReponseCrypt;
    void setupDeckModel(PTreeModel* deckModel);

protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::tab_search_crypt *ui;
    QCompleter *Completer;
    QPixmap DosCrypt;

private slots:
    void ClearForm();
    void RechercheCarte();
    void request_affichage(QModelIndex Idx);
    void deck_request_affichage(QModelIndex Idx);
    void AfficheImageCrypt(QString CardName);

signals:
    void new_card_selected(QString);
    void card_picture_missing(QString);
    void card_dropped(QStringList StrL);
};

#endif // TAB_SEARCH_CRYPT_H
