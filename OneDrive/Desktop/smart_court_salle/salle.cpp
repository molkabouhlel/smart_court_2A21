#include "salle.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QMessageBox>
#include <QPdfWriter>
#include <QPainter>
Salle::Salle()
{
num_salle=0;
departement=" ";juge=" ";suspect=" ",etage=0; //constructeurs par defaut
}

Salle::Salle(int num_salle, QString departement, int etage,QString juge, QString suspect) //constructeurs par copie
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
/*void Salle::pdf()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("C:/Users/Asus/OneDrive/Desktop/new_document.pdf");
    QPainter painter;
               painter.begin(&printer);
             painter.drawText(10, 80, "num_salle ");
              painter.drawText(10, 200, " departement ");
              painter.drawText(10, 300, " etage ");
              painter.drawText(10, 400, " juge ");
              painter.drawText(10, 500, " suspect ");

              painter.end();

              QString filename="C:/Users/Asus/Downloads/new_document.pdf";
              qDebug()<<"Print file name is "<<filename;
              if(!filename.isEmpty())
              {


                 QPrinter printer;
                  printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setOutputFileName(filename);

                  QPrintDialog dialog;
                  dialog.setWindowTitle("print document");
                  dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
                  dialog.exec();
              }
              else
                  qDebug()<<"empty";

              qDebug()<<"List of printers";
              QList<QPrinterInfo> printerList=QPrinterInfo::availablePrinters();
              foreach (QPrinterInfo printerInfo, printerList) {
                  qDebug()<<printerInfo.printerName();
              }
}*/
void  Salle::telechargerPDF(){


                    QPdfWriter pdf("‪C:/Users/Asus/OneDrive/Desktop/PDF.pdf");

                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::green);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"LISTES DES EMPLOYER");
                          painter.setPen(Qt::gray);
                          painter.setFont(QFont("Arial",14));
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"num de salle");
                          painter.drawText(1300,3300,"etage");
                          painter.drawText(2200,3300,"departement");
                          painter.drawText(3200,3300,"juge");
                          painter.drawText(4200,3300,"suspect");


                          QSqlQuery query;
                          query.prepare("select * from Salle");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(2).toString());
                              painter.drawText(2200,i,query.value(3).toString());
                              painter.drawText(3200,i,query.value(1).toString());
                              painter.drawText(5300,i,query.value(4).toString());
                              painter.drawText(6700,i,query.value(5).toString());


                             i = i + 500;
                          }}
