#include "salle.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
Salle::Salle()
{
num_salle=0;
departement=" ";juge=" ";suspect=" ",etage=0;
}

Salle::Salle(int num_salle, QString departement, int etage,QString juge, QString suspect)
{this->num_salle=num_salle;this->departement=departement,this->etage=etage;this->juge=juge;this->suspect=suspect;}
int Salle::getnum_salle(){return num_salle;}
QString Salle::getdepartement(){return departement ;}
int Salle::getetage(){return etage ;}
QString Salle::getjuge(){return juge;}
QString Salle::getsuspect(){return suspect;}
void Salle::setnum_salle(int num_salle){this->num_salle=num_salle;}
void Salle::setdepartement(QString departement){this->departement=departement;}
void Salle:: setetage(int etage){this->etage=etage;}
void Salle::setjuge(QString juge){this->juge=juge;}
void Salle::setsuspect(QString suspect){this->suspect=suspect;}
bool Salle::ajouter()
{
            QSqlQuery query;
            QString num_salle_string = QString::number(num_salle);
            QString etage_string = QString::number(etage);
                 query.prepare("INSERT INTO salle (num_salle,departement,etage,juge,suspect) "
                               "VALUES (:num_salle,:departement,:etage,:juge,:suspect)");
                 query.bindValue(":departement", departement);query.bindValue(":departement", departement);
                 query.bindValue(":num_salle", num_salle_string);
                 query.bindValue(":juge", juge);
                 query.bindValue(":suspect", suspect);
                 query.bindValue(":etage", etage_string);


    return   query.exec();
}
bool Salle::supprimer(int num_salle)
{
     QSqlQuery query;
     query.prepare("Delete from salle where num_salle=:num_salle");
     query.bindValue(":num_salle", num_salle);

return   query.exec();

}
QSqlQueryModel* Salle::afficher()
{
      QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM salle");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Num de la salle"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Département"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Etage"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Juge"));
    model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Suspect"));
    return  model;
}
bool Salle ::modifier()
{
                       QSqlQuery query;
                        QString num_salle_string=QString ::number (num_salle);
                        QString etage_string = QString::number(etage);
    query.prepare("UPDATE salle SET num_salle=:num_salle,departement=:departement,etage=:etage,juge=:juge,suspect=:suspect WHERE num_salle=:num_salle ");
                         query.bindValue(":num_salle",num_salle_string);
                         query.bindValue(":departement", departement);
                         query.bindValue(":etage", etage_string);
                         query.bindValue(":juge", juge);
                         query.bindValue(":suspect", suspect);

                     return query.exec();}
