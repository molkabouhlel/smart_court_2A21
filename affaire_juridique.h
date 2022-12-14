#ifndef AFFAIRE_JURIDIQUE_H
#define AFFAIRE_JURIDIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <string>
#include <QSqlQuery>
#include <QtDebug>
#include <QDateTime>
#include <QtCharts>
using namespace std;


class Affaire_juridique
{
     QString type,classe,nom,cause,description;
     //,option;
     QDateTime date;
     int code;
public:
    //constructeur
     Affaire_juridique();
     Affaire_juridique(QString,int, QDateTime,QString,QString,QString,QString);
                       //QString);

     //GETTERS
     QString getnom(){return nom;}
     int getcode(){return code;}
     QDateTime getdate(){return date;}
     QString getcause(){return cause;}
     QString gettype(){return type;}
     QString getclasse(){return classe;}
     QString getdescription(){return description ;}
     //QString getoption(){return option ;}


     //Les fonctions
     bool ajouter();
     QSqlQueryModel* afficher();
     bool modifier(int);
     bool supprimer(int,QString);

     QSqlQueryModel* recherchepardefaut(QString);
     QSqlQueryModel* rechercheparclasse(QString);
     QSqlQueryModel* recherchepartype(QString);

     QSqlQueryModel* TRIpardefaut();
     QSqlQueryModel* TRIparclasse();
     QSqlQueryModel* TRIpardate();
     QChart *  statAffaire();



};

#endif // AFFAIRE_JURIDIQUE_H
