#include "tab_gold_fich.h"
#include "ui_tab_gold_fich.h"

#include "PWidget.h"

tab_gold_fich::tab_gold_fich(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_gold_fich)
{
    ui->setupUi(this);

    PFrame* Bourse = new PFrame(this);
    TabledeJeu = new PGraphicsView(this);
    Scenedejeu = new PGraphicsScene();
    TabledeJeu->setScene(Scenedejeu);
}

void tab_gold_fich::initialisation(QString path) //rename in setPaths ??
{
   PathCartes = path;

   /*!!!!!!!!!!!!! TEST !!!!!!!!!!!!!!! */
   PGraphicsPixmapItem* CardItem  = new PGraphicsPixmapItem(QPixmap(PathCartes + "/" + "44magnum.jpg"),PGraphicsPixmapItem::CartedeLibrairie);
   PGraphicsPixmapItem* CardItem2 = new PGraphicsPixmapItem(QPixmap(PathCartes + "/" + "abiku.jpg"),PGraphicsPixmapItem::CartedeVampire);
   PGraphicsPixmapItem* CardItem3 = new PGraphicsPixmapItem(QPixmap(":icons/Blood.png"));

   CardItem2->setPos(1000,1000);
   CardItem3->setPos(400,600);
   Scenedejeu->addItem(CardItem);
   Scenedejeu->addItem(CardItem2);
   Scenedejeu->addItem(CardItem3);
}

tab_gold_fich::~tab_gold_fich()
{
    delete ui;
}
//#include <QGraphicsScene>
