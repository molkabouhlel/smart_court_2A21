#include "personnel.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QPdfWriter>
#include<QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QtPrintSupport/QPrinter>
#include"arduino.h"
#include<iostream>
#include<QDebug>
#include<QMessageBox>
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
   mot_de_passe="";
   gender="";
   mot_de_passe_parking="";
}
Personnel:: Personnel( int id,QString nom,QString prenom,QString date_n,QString lieu_t,int telephone,QString email,float salaire,QString grade,QString mot_de_passe,QString gender )
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
    this->mot_de_passe=mot_de_passe;
    this->gender=gender;
   // this->mot_de_passe_parking=mot_de_passe_parking;
}
bool Personnel::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id);
    QString telephone_string=QString::number(telephone);
    QString salaire_string=QString::number(salaire);
         query.prepare("INSERT INTO PERSONNEL (id, nom,prenom,date_n,lieu_t,telephone,email,salaire,grade,mot_de_passe,gender ) "
                       "VALUES (:id, :nom, :prenom, :date_n, :lieu_t, :telephone, :email, :salaire, :grade, :mot_de_passe, :gender )");
         query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
            query.bindValue(":date_n",date_n);
             query.bindValue(":lieu_t",lieu_t);
         query.bindValue(":telephone",telephone_string);
        query.bindValue(":email",email);
       query.bindValue(":salaire",salaire_string);
            query.bindValue(":grade", grade);
             query.bindValue(":mot_de_passe", mot_de_passe);
          query.bindValue(":gender", gender);

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
             model->setHeaderData(9, Qt::Horizontal, QObject::tr("mot_de_passe"));
             model->setHeaderData(10, Qt::Horizontal, QObject::tr("gender"));

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
            query.prepare("UPDATE PERSONNEL SET  id=:id, nom=:nom, prenom=:prenom, date_n=:date_n, lieu_t=:lieu_t, telephone=:telephone, email=:email, salaire=:salaire, grade=:grade, mot_de_passe=:mot_de_passe, gender=:gender WHERE id=:id");
            query.bindValue(":id",id_string);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
             query.bindValue(":date_n",date_n);
            query.bindValue(":lieu_t", lieu_t);
            query.bindValue(":telephone", telephone_string);
           query.bindValue(":email",email);
          query.bindValue(":salaire", salaire_string);
               query.bindValue(":grade", grade);
               query.bindValue(":mot_de_passe", mot_de_passe);
               query.bindValue(":gender", gender);

    return query.exec();
}

QSqlQueryModel* Personnel::chercher(int id)
{
    QSqlQueryModel* model=new  QSqlQueryModel();
         model->setQuery("select * from PERSONNEL where id="+QString::number(id));
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_n"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu_t"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));

         model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("salaire"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("grade"));
           model->setHeaderData(9, Qt::Horizontal, QObject::tr("mot_de_passe"));
           model->setHeaderData(10, Qt::Horizontal, QObject::tr("gender"));
        return model;
  }
QSqlQueryModel*Personnel::tri_id()
{
    QSqlQueryModel* model=new  QSqlQueryModel();
    model->setQuery("SELECT *FROM PERSONNEL ORDER BY id ASC");

   return model;
}
QSqlQueryModel* Personnel::tri_nom()
{
    QSqlQueryModel* model=new  QSqlQueryModel();
    model->setQuery("SELECT *FROM PERSONNEL ORDER BY nom ASC");

   return model;
}
QSqlQueryModel*Personnel::tri_salaire()
{
    QSqlQueryModel* model=new  QSqlQueryModel();
    model->setQuery("SELECT *FROM PERSONNEL ORDER BY salaire DESC");

   return model;
}


//arduino
bool Personnel::existance(QString id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM PERSONNEL WHERE id= ?");
    query.addBindValue(id);
    if(query.exec() )
    {
        while (query.next())
        {
            count ++;
        }
        if(count==1)
        {
            //msgBox.setText("id deja existe");
            //msgBox.exec();
            return 0;
        }

    }
    return 1;
}
