#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

tab_deck_tuning::tab_deck_tuning(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);
    ui->testbt->setIcon( QIcon(":/icons/delete.png") );
    ui->testbt->setStyleSheet("border: none;");

    // ///////////////////////////////////////////////
    // ASSOCIATION DES MODELES/VIEWS POUR LA GESTION DE DECK
    {
        // on map la vue définie private dans l'ui vers un membre de classe public
        DeckView = ui->PTreeViewDeckList;

        // on assigne le model de données
        ModeleDeck = new PTreeModel();
        ui->PTreeViewDeckList->setModel(ModeleDeck);

        // on assigne le delegate
        PDelegateDeck *DelegateDeck = new PDelegateDeck();
        ui->PTreeViewDeckList->setItemDelegate(DelegateDeck);
    }

    connect(ui->PTreeViewDeckList, SIGNAL(clicked(QModelIndex)), this, SLOT(AfficheCartesDeck(QModelIndex)));

}

void tab_deck_tuning::AfficheCartesDeck(QModelIndex Idx)
{
if (Idx.isValid())
    {
    QVariant CardData;
    QString CardName;
    QImage Image;
    QStandardItem* CurrentItem = ModeleDeck->itemFromIndex(Idx);

    if (CurrentItem->data(Qt::UserRole+1) == "LibraryCard" or CurrentItem->data(Qt::UserRole+1) == "CryptCard")
        {
        CardData = CurrentItem->data(Qt::UserRole);
        CardName = "/" + CardData.toStringList()[3] + ".jpg";
        // !!!!!!!!!! dépannage
        QString PathCartes;
        PathCartes = "D:\\Eternal-Deck-Builder\\bin\\debug\\Cartes\\";
        // !!!!!!!!!! dépannage
        if (Image.load(PathCartes + CardName))
            {ui->VisuelDeck->setPixmap(QPixmap::fromImage(Image));}
        else
            {
            emit card_picture_missing(CardName);
            /*Afficher un truc par defaut genre Vtes_Grelarge.gif*/
            }
        }
    }
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}
