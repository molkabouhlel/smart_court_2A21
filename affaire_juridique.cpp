#include "affaire_juridique.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QStandardItemModel>
#include<QObject>
Affaire_juridique::Affaire_juridique()
{
code=0;nom="" ;type="";classe="";cause=""; date=""; description="" ;
//option="";
}

Affaire_juridique::Affaire_juridique(QString nom,int code,QString date,QString cause,QString type,QString classe,QString description)
                                     //QString option)
{
this->nom=nom;
this->code=code;
this->date=date;
this->cause=cause;
this->type=type;
this->classe=classe;
this->description=description;
//this->option=option;
}

bool Affaire_juridique::ajouter()
{

    QSqlQuery query;
    QString code_string= QString::number(code);
    //QString date_string= QString::date(date);
          query.prepare("INSERT INTO AFFAIRES_JURIDIQUES (code,nom,type,dates,classe,description,causes,options) "
                        "VALUES (:code, :nom ,:type ,:dates ,:classe ,:description ,:cause ,:options)");
          query.addBindValue(code_string);
          query.addBindValue(nom);
          query.addBindValue(type);
          query.addBindValue(date);
          query.addBindValue(classe);
          query.addBindValue(description);
          query.addBindValue(cause);
          //query.bindValue(option );
          return query.exec();
}


QSqlQueryModel* Affaire_juridique::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM AFFAIRES_JURIDIQUES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("cause"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("options"));

    return model;
}


bool Affaire_juridique::modifier(int code)
{

    QSqlQuery query;
    QString mod= QString::number(code);
            query.prepare("UPDATE AFFAIRES_JURIDIQUES SET nom=:nom, type=:type, dates=:dates, classe=:classe, description=:description ,causes=:causes, options=:options WHERE code=:code");
            query.bindValue(":code", mod );
            query.bindValue(":nom", nom);
            query.bindValue(":type", type);
            query.bindValue(":dates", date);
            query.bindValue(":classe",classe);
            query.bindValue(":description", description);
            query.bindValue(":causes", cause);

    return query.exec();
}
bool Affaire_juridique::supprimer(int code,QString nom)
{
    QSqlQuery query;
    QString supp= QString::number(code);
    query.prepare("Delete from AFFAIRES_JURIDIQUES WHERE code=:code OR nom=:nom ");
    query.bindValue(":code", supp );
    query.bindValue(":nom", nom);
    return query.exec();
}
