#include "suspet.h"
#include "stmp.h"
#include "mainwindow.h"
#include<QPrintDialog>
#include<QPrinterInfo>
#include <QString>


Suspet::Suspet()
{
    id=0;
    nom="";
    prenom="";
}

Suspet::Suspet(int a,QString b,QString c,QString d,QDate e,QString f,int g,int h,QString i)
{
    this->id=a;
    this->nom=b;
    this->prenom=c;
    this->adresse=d;
    this->date_naissance=e;
    this->case_id=f;
    this->numero1=g;
    this->numero2=h;
    this->mail=i;

}
bool Suspet::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString n1_string=QString::number(numero1);
    QString n2_string=QString::number(numero2);



    query.prepare("INSERT INTO SUSPET (id, nom,prenom,adresse,date_naissance,case_id,numero1,numero2,mail) "
                  "VALUES (:id, :nom, :prenom ,:adress,:date_naissance,:case_id,:numero1,:numero2,:mail)");
    query.bindValue(":id",id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adress", adresse);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":case_id", case_id);
    query.bindValue(":numero1", n1_string);
    query.bindValue(":numero2", n2_string);
    query.bindValue(":mail", mail);


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
QSqlQueryModel * Suspet::recherche(QString id)/*cherche un producteur de meme id*/
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM SUSPET WHERE ID LIKE '"+id+"'  ");

    return model;
}
bool Suspet::existance(QString id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM Suspet WHERE id= ?");
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
QSqlQueryModel * Suspet::trier(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;

    if(test==1)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY DATE_NAISSANCE ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY NOM ASC ") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY ID ASC ") ;
    }

    if (query.exec()&&query.next())
    {
        model->setQuery(query) ;
    }
    return model;

}

