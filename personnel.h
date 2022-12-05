#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "arduino.h"
#include <QtCharts>
class Personnel
{
public:
    //const
    Personnel();
     Personnel( int,QString,QString,QString,QString,int,QString,float,QString ,QString,QString);
     // getters
     QString getnom(){return nom ;}

     QString getprenom()
     {
         return prenom;
     }
     int getid(){return id;}
     QString getgrade()
     {
    return grade;
     }
    QString getlieu_t(){return lieu_t;}
    QString getmot_de_passe(){return mot_de_passe;}
    // setteurs
    void setnom(QString n ){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setid (int id){this->id=id;}
    void setgrade(QString nvg){grade=nvg;}
    void setlieu_t(QString lieu_t){this->lieu_t=lieu_t;}
    void setmot_passe(QString mot_de_passe){this->mot_de_passe=mot_de_passe;}
    //cruds
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier();
QSqlQueryModel*chercher(int);
QSqlQueryModel*tri_id();
QSqlQueryModel*tri_nom();
QSqlQueryModel*tri_salaire();
bool telechargerPDF();
bool existance(QString );
QChart* statistique_chart();


private:
    int id;
  QString nom;
  QString prenom;
 QString date_n;
  QString lieu_t;
  int telephone;
  QString email;
  float salaire;
 QString grade;
 QString mot_de_passe;
 QString gender;
  QString mot_de_passe_parking;
 //arduino a;
};

#endif // PERSONNEL_H
