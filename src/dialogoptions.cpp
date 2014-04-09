#include "dialogoptions.h"
#include "ui_dialogoptions.h"

DialogOptions::DialogOptions(QWidget *parent) : QDialog(parent), ui(new Ui::DialogOptions)
{
/* On construit la fenetre modélisée dans Qt Creator*/
 ui->setupUi(this);

/* On procéde aux initialisations complémentaires */
 this->setFixedSize(this->size());
 LoadOptions();

/* On définie les connections */
 this->connect(ui->pBOk, SIGNAL(clicked()), this, SLOT(QuitWithChange()));
 this->connect(ui->pBCancel, SIGNAL(clicked()), this, SLOT(QuitWithoutchange()));
 this->connect(ui->pBApply, SIGNAL(clicked()), this, SLOT(ApplyChange()));
}

void DialogOptions::QuitWithChange()
{
if (SaveOptions())
    {
     qDebug() << "QuitWithChange et je suis dans le TRUE";
    }
else
    {
     qDebug() << "QuitWithChange et je suis dans le FALSE";
    }

 this->close();
}
void DialogOptions::QuitWithoutchange()
{
 qDebug() << "QuitWithoutchange";
 this->close();
}
void DialogOptions::ApplyChange()
{
 if (SaveOptions())
     {
      qDebug() << "ApplyChange et je suis dans le TRUE";
     }
 else
     {
      qDebug() << "ApplyChange et je suis dans le FALSE";
     }
}
bool DialogOptions::SaveOptions()
{
 qDebug() << "SaveOptions";
 QSettings settings("./cfg.ini", QSettings::IniFormat);

 if (this->ui->rBA4->isChecked())
    { settings.setValue("PrintFormat","A4"); }
 else
    { settings.setValue("PrintFormat","A3"); }

 return(true);
}
void DialogOptions::LoadOptions()
{
 QSettings settings("./cfg.ini", QSettings::IniFormat);
 this->PrintFormat = settings.value("PrintFormat", "A4").toString();
 if (PrintFormat == "A4")
    { this->ui->rBA4->setChecked(true); }
 else
    { this->ui->rBA3->setChecked(true); }

 qDebug() << "LoadOptions";
}

DialogOptions::~DialogOptions()
{
    delete ui;
}
