#include "suspet.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>

Suspet::Suspet()
{
id=0;
nom="";
prenom="";
}

Suspet::Suspet(int a,QString b,QString c,QString d,QDate e,QString f,int g,int h)
{
    this->id=a;
    this->nom=b;
    this->prenom=c;
    this->adresse=d;
    this->date_naissance=e;
    this->case_id=f;
    this->numero1=g;
    this->numero2=h;

}
bool Suspet::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString n1_string=QString::number(numero1);
    QString n2_string=QString::number(numero2);



         query.prepare("INSERT INTO SUSPET (id, nom,prenom,adresse,date_naissance,case_id,numero1,numero2) "
                       "VALUES (:id, :nom, :prenom ,:adress,:date_naissance,:case_id,:numero1,:numero2)");
         query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":adress", adresse);
            query.bindValue(":date_naissance", date_naissance);
            query.bindValue(":case_id", case_id);
            query.bindValue(":numero1", n1_string);
             query.bindValue(":numero2", n2_string);

        return  query.exec();
}
QSqlQueryModel * Suspet::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM SUSPET");
     return model;
 }

  bool Suspet:: supprimer(int id)
  {
      QSqlQuery query;
      query.prepare("delete from SUSPET where id=:id");
      query.bindValue(":id",id);
        return  query.exec();
  }

