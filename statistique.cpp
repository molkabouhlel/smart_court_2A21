#include "statistique.h"
#include "ui_statistique.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
}

Statistique::~Statistique()
{
    delete ui;
}
void Statistique::statistique()
{
    QSqlQuery query0,query1,query2,query3,query4,query5,query6;

    qreal tot=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;


    query0.prepare("SELECT * FROM PERSONNEL");
    query0.exec();


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

    while (query0.next()){tot++;}
    while (query1.next()){p1++;}
    while (query2.next()){p2++;}
  while (query3.next()){p3++;}
    while (query4.next()){p4++;}
    while (query5.next()){p5++;}
      while (query6.next()){p6++;}

   tot=tot/2;



    // forme + pourcntage + chnia cercule
    QPieSeries *series = new QPieSeries();
    series->append("femme",p1);
    series->append("homme",p2);
    series->append("lieu_t tunis",p3);
    series->append("lieu_t ariana",p4);
    series->append("ingenieur",p3);
    series->append("technician",p4);
    //

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
           chart->addSeries(series);
        //  chart->setTitle("statistique des personnels");
   //       chart->legend()->show();//identi afficher la forme

 //display
   QChartView *chartView=new QChartView(chart,ui->label_stat);
   chartView->setRenderHint(QPainter::Antialiasing);//rendre le donner sur le painter
        chartView->setMinimumSize(900,900);
   chartView->show();

}


