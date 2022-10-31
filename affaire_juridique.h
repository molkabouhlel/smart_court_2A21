#ifndef AFFAIRE_JURIDIQUE_H
#define AFFAIRE_JURIDIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <string>
#include <QSqlQuery>
#include <QtDebug>


using namespace std;

/*struct date{             //STRUCTURE DATE
  int day,month,year,hour,min;
  string  time;
};*/

class Affaire_juridique
{
     QString type,classe,nom,cause,date,description;
     //,option;
     //struct date date;
     int code;
public:
    //constructeur
     Affaire_juridique();
     Affaire_juridique(QString,int,QString,QString,QString,QString,QString);
                       //QString);

     //GETTERS
     QString getnom(){return nom;}
     int getcode(){return code;}
     QString getdate(){return date;}
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


};

#endif // AFFAIRE_JURIDIQUE_H
