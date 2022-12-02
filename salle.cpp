#include "salle.h"
#include "smtp.h"

#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QMessageBox>
#include <QPdfWriter>
#include <QPainter>
//#include<QtPrintSupport/QPrinter>
#include<QPrinterInfo>
#include<QPrintDialog>
#include<QPrinter>
#include<iostream>
#define STR_EQUAL 0
using namespace std;
Salle::Salle()
{
    num_salle=0;
    departement=" ";
    juge=" ";
    suspect=" ",etage=0; //constructeurs par defaut
}

Salle::Salle(int num_salle, QString departement, int etage,QString juge, QString suspect) //constructeurs par copie
{
    this->num_salle=num_salle;
    this->departement=departement,this->etage=etage;
    this->juge=juge;
    this->suspect=suspect;
}
int Salle::getnum_salle()
{
    return num_salle;
}
QString Salle::getdepartement()
{
    return departement ;
}
int Salle::getetage()
{
    return etage ;
}
QString Salle::getjuge()
{
    return juge;
}
QString Salle::getsuspect()
{
    return suspect;
}
void Salle::setnum_salle(int num_salle)
{
    this->num_salle=num_salle;
}
void Salle::setdepartement(QString departement)
{
    this->departement=departement;
}
void Salle:: setetage(int etage)
{
    this->etage=etage;
}
void Salle::setjuge(QString juge)
{
    this->juge=juge;
}
void Salle::setsuspect(QString suspect)
{
    this->suspect=suspect;
}
bool Salle::ajouter()
{
    QSqlQuery query;
    QString num_salle_string = QString::number(num_salle);
    QString etage_string = QString::number(etage);
    query.prepare("INSERT INTO salle (num_salle,departement,etage,juge,suspect) "
                  "VALUES (:num_salle,:departement,:etage,:juge,:suspect)");
    query.bindValue(":departement", departement);
    query.bindValue(":departement", departement);
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

    return query.exec();
}
bool Salle::existance(QString num_salle)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM salle WHERE num_salle= ?");
    query.addBindValue(num_salle);
    if(query.exec() )
    {
        while (query.next())
        {
            count ++;
        }
        if(count==1)
        {
            msgBox.setText("salle deja existe");
            msgBox.exec();
            return 0;
        }

    }
    return 1;
}
QSqlQueryModel * Salle::recherche(QString num_salle)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM SALLE WHERE NUM_SALLE LIKE '"+num_salle+"'  ");

    return model;
}
QSqlQueryModel * Salle::trier(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;

    if(test==1)
    {
        query.prepare("SELECT *  FROM SALLE ORDER BY DEPARTEMENT ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM SALLE ORDER BY ETAGE ASC ") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM SALLE ORDER BY NUM_SALLE ASC ") ;
    }

    if (query.exec()&&query.next())
    {
        model->setQuery(query) ;
    }
    return model;

}

void  Salle::telechargerPDF()
{
//QPdfWriter pdf("C:/Users/Asus/OneDrive/Desktop/smart_court_salle/PDF0/Sallepdf");
    QPdfWriter pdf("C:/Users/Asus/OneDrive/Desktop/Salle.pdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::blue);//titre
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(1100,1200,"LISTES DES SALLES");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial",14));
                             // painter.drawRect(100,100,7300,2600);
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial",11));
                              painter.drawText(200,3300,"NUM_SALLE");
                              painter.drawText(1300,3300,"DEPARTEMENT");
                              painter.drawText(2700,3300,"ETAGE");
                              painter.drawText(4000,3300,"JUGE");
                              painter.drawText(6500,3300,"SUSPECT");


                              QSqlQuery query;

                              query.prepare("select * from salle");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(200,i,query.value(0).toString());
                                  painter.drawText(1300,i,query.value(1).toString());
                                  painter.drawText(2700,i,query.value(2).toString());
                                  painter.drawText(4000,i,query.value(3).toString());
                                  painter.drawText(6500,i,query.value(4).toString());



                                 i = i + 500;

    }
}
