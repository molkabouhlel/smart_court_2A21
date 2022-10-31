#include "salle.h"
#include <QSqlQuery>
#include <QtDebug>

Salle::Salle()
{   num_salle=0;
    departement="";
    etage=0;
    juge="";
    suspect="";

}
Salle::Salle(int num_salle,QString departement,int etage,QString juge,QString suspect )
{
    this->num_salle=num_salle;
    this->departement=departement;
    this->etage=etage;
    this->juge=juge;
    this->suspect=suspect;
}


bool Salle::ajouter()
{bool test=false;





    QSqlQuery query;
    QString num_salle_string=QString::number(num_salle);
    QString etage_string=QString::number(etage);
    query.prepare("INSERT INTO salle (num_salle,departement,etage,juge,suspect) "
                  "VALUES (:num_salle,:departement,:etage,:juge,:suspect)");
    query.bindValue(":num_salle", num_salle);
    query.bindValue(":departement", departement);
    query.bindValue(":etage",etage );
    query.bindValue(":juge",juge );
    query.bindValue(":suspect",suspect );
    return query.exec();
    return test;
}
QSqlQueryModel * Salle::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM personnel");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_Naissance"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieu_travail"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("email"));
                model->setHeaderData(8, Qt::Horizontal, QObject::tr("salaire"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));

    return model;
}

/*bool Personnel::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id);
    QString date_n_string=QString::number(date_n);
    QString telephone_string=QString::number(telephone);
    QString salaire_string=QString::number(salaire);
         query.prepare("INSERT INTO personnel (id, nom,prenom,date_n,lieu_t,telephone,email,salaire,grade) "
                       "VALUES (:id, :forename, :surname, :date, :place, :telephone, :email, :wage, :grade)");
         query.bindValue(":id",id_string);
          query.bindValue(":forename", "nom");
           query.bindValue(":surname", "prenom");
            query.bindValue(":date",date_n);
             query.bindValue(":palce", "lieu_t");
         query.bindValue(":telephone", telephone);
        query.bindValue(":email","email");
       query.bindValue(":wage", salaire);
            query.bindValue(":grade", "grade");
        return  query.exec();
}
 QSqlQueryModel * Personnel::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM personnel");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_Naissance"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieu_travail"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone"));
                model->setHeaderData(7, Qt::Horizontal, QObject::tr("email"));
                 model->setHeaderData(8, Qt::Horizontal, QObject::tr("salaire"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));

     return model;
 }
  bool Personnel:: supprimer(int id)
  {
      QSqlQuery query;
           query.prepare("delete from personnel where id=:id");
    query.bindValue(":id",id);
        return  query.exec();
  }
*/
