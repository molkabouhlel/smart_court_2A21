#ifndef CALENDRIER_H
#define CALENDRIER_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QtCharts>
class Calendrier
{
private:
    QString id_r, type_r,local,date_d,date_f;
    int nb_per;


public:
    Calendrier();
    Calendrier(QString,QString,QString,QString,int,QString);
    QString getid_r(){return id_r;}
     QString gettype_r(){return type_r;}
      QString getdate_d(){return date_d;}
       QString getdate_f(){return date_f;}
       int getnb_per(){return nb_per;}
       void setid_r(QString id_r ){this->id_r=id_r;}
       void settype_r(QString type_r){this->type_r=type_r;}
       void setlocal(QString local){this->local=local;}
       void setdate_d(QString date_d){this->date_d=date_d;}
       void setdate_f(QString date_f){this->date_f=date_f;}
       void setnb_per(int nb_per){this->nb_per=nb_per;}
       bool ajouter();
        bool supprimer(QString);
          bool modifiers(QString);
           QSqlQueryModel * afficher();

           QSqlQueryModel * rechercher(QString );
           QSqlQueryModel * AfficherTri();

           QChart *  stat();
QSqlQueryModel *AfficherTriid();
QSqlQueryModel * AfficherTritype();



};

#endif // CALENDRIER_H
