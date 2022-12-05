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
            query.prepare("UPDATE PERSONNELs SET  id=:id, nom=:nom, prenom=:prenom, date_n=:date_n, lieu_t=:lieu_t, telephone=:telephone, email=:email, salaire=:salaire, grade=:grade, mot_de_passe=:mot_de_passe, gender=:gender WHERE id=:id");
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



QChart * Personnel::statistique_chart()
{
    QSqlQuery query0,query1,query2,query3,query4,query5,query6,query8,query7;

    qreal c1_1=0,c1_2=0,c1_3=0,c1_4=0
                ,c2_1=0 ,c2_2=0;

    int totale=0;

        query0.prepare("SELECT * FROM PERSONNEL");
        query0.exec();

        //Les classes de type violation
        query1.prepare("SELECT * FROM PERSONNEL WHERE GENDER='femme'");
        query1.exec();

        query2.prepare("SELECT * FROM PERSONNEL WHERE GENDER='homme' ");
        query2.exec();

        query3.prepare("SELECT * FROM PERSONNEL WHERE lieu_t='tunis' ");
        query3.exec();

        query4.prepare("SELECT * FROM PERSONNEL WHERE lieu_t='ariana' ");
        query4.exec();

        query5.prepare("SELECT * FROM PERSONNEL WHERE grade='ing' ");
        query5.exec();

        query6.prepare("SELECT * FROM PERSONNEL WHERE grade='technician' ");
        query6.exec();





        while (query0.next()){totale++;}
        //total des classes par rapport au type violation
        while (query1.next()){c1_1++;}
        while (query2.next()){c1_2++;}
        while (query3.next()){c1_3++;}
        while (query4.next()){c1_4++;}
        while (query5.next()){c2_1++;}
        while (query6.next()){c2_2++;}


        totale=totale/2;


        // Assign names to the set of bars used
                QBarSet *set0 = new QBarSet(" grade:ing");
                QBarSet *set1 = new QBarSet("grade:technician");
                QBarSet *set2 = new QBarSet("lieu_t:tunis");
                QBarSet *set3 = new QBarSet("lieu_t:ariana ");

                // Assign values for each bar
                *set0 << c1_3;
                *set1 << c1_4;
                 *set2<< c2_1;
                 *set3<< c2_2;

                // Add all sets of data to the chart as a whole
                // 1. Bar Chart
                QBarSeries *series = new QBarSeries();

                // 2. Stacked bar chart
                series->append(set0);
                series->append(set1);
                series->append(set2);
                series->append(set3);

                // Used to define the bar chart to display, title
                // legend,
                QChart *chart = new QChart();

                // Add the chart
                chart->addSeries(series);
                chart->setTitle("statistique Personnel");
                chart->setAnimationOptions(QChart::SeriesAnimations);
                chart->setTheme( QChart::ChartThemeBlueCerulean);

                QStringList gender;
                    gender << "femme" << "homme"  ;
                // Adds categories to the axes
                    QBarCategoryAxis *axisX = new QBarCategoryAxis();
                        axisX->append(gender);
                        chart->addAxis(axisX, Qt::AlignBottom);
                        series->attachAxis(axisX);

                        QValueAxis *axisY = new QValueAxis();
                        axisY->setRange(0,totale);
                        chart->addAxis(axisY, Qt::AlignLeft);
                        series->attachAxis(axisY);


                // 1. Bar chart
               // chart->setAxisX(axis, series);

                // Used to change the palette
                QPalette pal = qApp->palette();

                // Change the color around the chart widget and text
                pal.setColor(QPalette::Window, QRgb(0xffffff));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));

                // Apply palette changes to the application
                qApp->setPalette(pal);
return chart;
}
