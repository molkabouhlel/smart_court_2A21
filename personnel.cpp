#include "personnel.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
Personnel::Personnel()
{
   id=0;
   nom="";
   prenom="";
   date_n="";
   lieu_t="";
   telephone=0;
   email="";
   salaire=0;
   grade="";
}
Personnel:: Personnel( int id,QString nom,QString prenom,QString date_n,QString lieu_t,int telephone,QString email,float salaire,QString grade )
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date_n=date_n;
    this->lieu_t=lieu_t;
    this->telephone=telephone;
    this->email=email;
    this->salaire=salaire;
    this->grade=grade;
}
bool Personnel::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id);
    QString telephone_string=QString::number(telephone);
    QString salaire_string=QString::number(salaire);
         query.prepare("INSERT INTO PERSONNEL (id, nom,prenom,date_n,lieu_t,telephone,email,salaire,grade) "
                       "VALUES (:id, :nom, :prenom, :date_n, :lieu_t, :telephone, :email, :salaire, :grade)");
         query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
            query.bindValue(":date_n",date_n);
             query.bindValue(":lieu_t",lieu_t);
         query.bindValue(":telephone",telephone_string);
        query.bindValue(":email",email);
       query.bindValue(":salaire",salaire_string);
            query.bindValue(":grade", grade);
        return  query.exec();
}
 QSqlQueryModel * Personnel::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM PERSONNEL");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_N"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu_t"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("salaire"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("grade"));

     return model;
 }
  bool Personnel:: supprimer(int id)
  {
      QSqlQuery query;
           query.prepare("delete from PERSONNEL where id=:id");
    query.bindValue(":id",id);
        return  query.exec();
  }
bool Personnel:: modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(id);
    QString telephone_string=QString::number(telephone);
    QString salaire_string=QString::number(salaire);
            query.prepare("UPDATE PERSONNEL SET  id=:id, nom=:nom, prenom=:prenom, date_n=:date_n, lieu_t=:lieu_t, telephone=:telephone, email=:email, salaire=:salaire, grade=:grade WHERE id=:id");
            query.bindValue(":id",id_string);
            query.bindValue(":nom", nom);
            query.bindValue(":sprenom", prenom);
             query.bindValue(":date_n",date_n);
            query.bindValue(":lieu_t", lieu_t);
            query.bindValue(":telephone", telephone_string);
           query.bindValue(":email",email);
          query.bindValue(":salaire", salaire_string);
               query.bindValue(":grade", grade);

    return query.exec();
}

