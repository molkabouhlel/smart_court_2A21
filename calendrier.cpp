#include "calendrier.h"
#include<QDebug>
#include<QObject>
Calendrier::Calendrier()
{
id_r="";
date_d="";
date_f="";
type_r="";
nb_per=0;
local="";


}



Calendrier::Calendrier (QString id_r ,QString date_d,QString date_f ,QString local,int nb_per,QString type_r)
{
    this->id_r=id_r;
    this->date_d=date_d;
    this->date_f=date_f;
    this->type_r=type_r;
    this->nb_per=nb_per;
    this->local=local;



}

bool Calendrier::ajouter(){

QSqlQuery query;
QString du = QString::number(nb_per);
query.prepare("insert into calendrier (id_r, date_d, date_f,type_r,nb_per,local) "
                        "VALUES (:id_r, :date_d, :date_f,:type_r,:nb_per,:local)");
          query.bindValue(":id_r", id_r);
          query.bindValue(":date_d",date_d);
          query.bindValue(":date_f", date_f);
          query.bindValue(":type_r",type_r);

query.bindValue(":nb_per",du);
          query.bindValue(":local",local);



return query.exec();
}
QSqlQueryModel * Calendrier:: afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CALENDRIER");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_F"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_R"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_PER"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("LOCAL"));
    return  model ;
}



bool Calendrier::supprimer(QString id_r){
QSqlQuery query;
query.prepare("Delete from CALENDRIER where id_r=:id");
query.bindValue(":id", id_r);
return query.exec();
}


bool Calendrier::modifiers (QString id_r)
{
    QSqlQuery query;
    QString du = QString::number(nb_per);
   query.prepare("update calendrier set  date_d = :date_d,date_f=:date_f, type_r=:type_r , nb_per=:nb_per , local=:local WHERE id_r=:id");

    query.bindValue(":id", id_r);
    query.bindValue(":date_d",date_d);
    query.bindValue(":date_f", date_f);
    query.bindValue(":type_r",type_r);
    query.bindValue(":nb_per",du);
    query.bindValue(":local",local);



return query.exec();
}
QSqlQueryModel * Calendrier::rechercher(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from calendrier where type_r like '"+nom+"%' or id_r LIKE '"+nom+"%'  ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
QSqlQueryModel * Calendrier::AfficherTri()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM calendrier ORDER BY date_d");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_F"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_R"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_PER"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("LOCAL"));
    return model;
}
QSqlQueryModel * Calendrier::AfficherTriid()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM calendrier ORDER BY ID_R");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_F"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_R"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_PER"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("LOCAL"));
    return model;
}
QSqlQueryModel * Calendrier::AfficherTritype()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM calendrier ORDER BY type_r");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_F"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_R"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_PER"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("LOCAL"));
    return model;
}




QChart * Calendrier ::stat(){
QSqlQuery q,q1,q2,q3,q4,q5;
   q.exec("Select * from calendrier");
   int tot=0;
   while (q.next())
       tot++;
  qDebug() << "total =" << tot;
   q1.prepare("Select * from calendrier where type_r = :nom ");
   q1.bindValue(":nom","civil");
   q1.exec();

   int tot_don=0;
   while (q1.next())
       tot_don++;
qDebug() << "pourcentage don =" << tot_don;
   qreal pour_civil=(tot_don*100)/tot;

   q2.prepare("Select *from calendrier where type_r = :nom  ");
   q2.bindValue(":nom","criminel");
   q2.exec();
   int tot_event=0;
   while (q2.next())
       tot_event++;

   qreal pour_criminel=(tot_event*100)/tot;

   q3.prepare("Select * from calendrier where type_r = :nom  ");
   q3.bindValue(":nom","administrative");
   q3.exec();
   int tot_dep=0;
   while (q3.next())
       tot_dep++;
   qreal pour_administrative=(tot_dep*100)/tot;



   QPieSeries *series = new QPieSeries();
    series->append("civil",pour_civil);
    series->append("criminel",pour_criminel);
    series->append("administrative",pour_administrative);

    QPieSlice *slice0= series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);

    slice1->setLabelVisible();

    slice1->setBrush(Qt::green);

    QPieSlice *slice2= series->slices().at(2);
    slice2->setLabelVisible();
     slice2->setBrush(Qt::red);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("type des evenements");
    chart->legend()->hide();
    series->setLabelsVisible();

        for(auto slice : series->slices())
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));
//chart->setBackgroundBrush(Qt::transparent);



   return chart;
}

