#include <QDebug>
#include <QStringList>
#include <QNetworkReply>

#include "update_manager.h"


update_manager::update_manager(QObject *parent) : QObject(parent)
{
    // on crée le manager
    QNetworkAccessManager manager (this);
    // lors d'une requete à un serveur demandant authentification, on setup la connec dans le slot authentification
    connect( &manager, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)), this, SLOT(authentification(QNetworkReply*, QAuthenticator*)));
}

void update_manager::set_card_directory(QString dir_path_card)
{
    dir_card = dir_path_card;
}

void update_manager::set_serv_settings(QString path, QString user, QString pass)
{
    srv_path = path;
    srv_user = user;
    srv_pass = pass;
}

void update_manager::authentification(QNetworkReply* reply, QAuthenticator* auth)
{
    auth->setUser(srv_user);
    auth->setPassword(srv_pass);
}

void update_manager::erreur(QNetworkReply::NetworkError code)
{
    // on signal qu'une erreur s'est produit
    qDebug() << "update_manager error code n°" << code ;
}

// requête d'une image de carte au serveur
void update_manager::seek_card_picture(const QString card_name)
{
    QUrl url;
    url.setScheme("ftp");
    url.setUserName(srv_user);
    url.setPassword(srv_pass);
    url.setHost(srv_path);
    url.setPort(21);
    url.setPath("/Cartes/" + card_name);

    QNetworkReply *reply = manager.get( QNetworkRequest(url) );
    connect( reply, SIGNAL( finished() ),  this , SLOT( write_card_picture() ) );
    connect( reply, SIGNAL( error(QNetworkReply::NetworkError) ), this, SLOT( erreur(QNetworkReply::NetworkError) ) );
}

void update_manager::write_card_picture()
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());

    QString card_name = r->url().path().split("/").last();

    QFile *f = new QFile ( dir_card + "/" + card_name, this );
    if ( f->open(QIODevice::WriteOnly) )
        {
        // on ecrit dedans
        f->write(r->readAll());
        // on le ferme
        f->close();
        r->deleteLater();
        }
}

// requête d'un fichier de base de données
void update_manager::seek_database()
{

}

// copie du fichier bdd en local + gestion des conflits si ancienne dbb de mm nom ?
void update_manager::write_database()
{

}

// destructeur uselees pour le moment
update_manager::~update_manager()
{
}
