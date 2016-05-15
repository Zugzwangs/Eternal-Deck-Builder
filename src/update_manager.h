#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QFile>
#include <QUrl>

class update_manager : public QObject
{
    Q_OBJECT

public:
    update_manager(QObject * parent = 0);
    ~update_manager();

public slots:
    // settings serv ftp à utiliser, dossiers de dl...
    void set_card_directory(QString dir_path_card);
    void set_serv_settings(QString path, QString user, QString pass = "");
    // va dl le scan de la carte 'card_name" sur le ftp setup précédemment
    void seek_card_picture(const QString card_name);
    // met à jour les bases de données internes (MAJ dépendance TEDB)
    void seek_database();

private slots:
    // gere l'authentification au serv ftp
    void authentification(QNetworkReply * reply, QAuthenticator *auth);
    // gestion d'erreur des requetes
    void erreur(QNetworkReply::NetworkError code);
    // copie en local les images téléchargées
    void write_card_picture();
    // met à jour la bdd locale
    void write_database();

private:
    QNetworkAccessManager manager;
    QString srv_path;
    QString srv_user;
    QString srv_pass;
    QString dir_card;

signals:
    void picture_downloaded();
};

#endif // UPDATE_MANAGER_H



