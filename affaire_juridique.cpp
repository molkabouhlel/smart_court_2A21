#include "affaire_juridique.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QStandardItemModel>
#include<QObject>
Affaire_juridique::Affaire_juridique()
{
code=0;nom="" ;type="";classe="";cause="";description="" ;
//option="";
}

Affaire_juridique::Affaire_juridique(QString nom,int code, QDateTime  date,QString cause,QString type,QString classe,QString description)                                     //QString option)
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
          //query.addbindValue(option );
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
            //query.bindValue(":options", option);

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

QSqlQueryModel* Affaire_juridique::recherchepardefaut(QString nom_recherche)
{
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("SELECT* FROM AFFAIRES_JURIDIQUES where nom like '"+nom_recherche+"%'");
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

QSqlQueryModel* Affaire_juridique::rechercheparclasse(QString classe_recherche)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM AFFAIRES_JURIDIQUES where classe like '"+classe_recherche+"%'");
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
QSqlQueryModel* Affaire_juridique::recherchepartype(QString type_recherche)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM AFFAIRES_JURIDIQUES where type like '"+type_recherche+"%'");
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


QSqlQueryModel * Affaire_juridique::TRIpardefaut()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM AFFAIRES_JURIDIQUES ORDER BY code ASC");
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
QSqlQueryModel * Affaire_juridique::TRIparclasse()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM AFFAIRES_JURIDIQUES ORDER BY classe ASC");
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
QSqlQueryModel * Affaire_juridique::TRIpardate()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM AFFAIRES_JURIDIQUES ORDER BY dates ASC");
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

QChart * Affaire_juridique::statAffaire()
{
    QSqlQuery q0,q1_1,q1_2,q1_3,q1_4
            ,q2_1,q2_2,q2_3,q2_4
            ,q3_1,q3_2,q3_3,q3_4;
int tot=0;
    qreal c1_1=0,c1_2=0,c1_3=0,c1_4=0
            ,c2_1=0 ,c2_2=0 ,c2_3=0,c2_4=0
            ,c3_1=0 ,c3_2=0 ,c3_3=0,c3_4=0;


    q0.prepare("SELECT * FROM AFFAIRES_JURIDIQUES");
    q0.exec();

    //Les classes de type violation
    q1_1.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='A' and type='Violation'");
    q1_1.exec();

    q1_2.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='B' and type='Violation'");
    q1_2.exec();

    q1_3.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='C' and type='Violation' ");
    q1_3.exec();

    q1_4.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='D' and type='Violation' ");
    q1_4.exec();

    //Les classes de type Misdemeanors
    q2_1.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='A' and type='Misdemeanors'");
    q2_1.exec();

    q2_2.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='B' and type='Misdemeanors'");
    q2_2.exec();

    q2_3.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='C' and type='Misdemeanors' ");
    q2_3.exec();

    q2_4.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='D' and type='Misdemeanors' ");
    q2_4.exec();

    //Les classes de type Felonies
    q3_1.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='A' and type='Felonies'");
    q3_1.exec();

    q3_2.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='B' and type='Felonies'");
    q3_2.exec();

    q3_3.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='C' and type='Felonies' ");
    q3_3.exec();

    q3_4.prepare("SELECT * FROM AFFAIRES_JURIDIQUES WHERE classe='D' and type='Felonies' ");
    q3_4.exec();


    while (q0.next()){tot++;}
    //total des classes par rapport au type violation
    while (q1_1.next()){c1_1++;}
    while (q1_2.next()){c1_2++;}
    while (q1_3.next()){c1_3++;}
    while (q1_4.next()){c1_4++;}
    //total des classes par rapport au type Misdemeanors
    while (q2_1.next()){c2_1++;}
    while (q2_2.next()){c2_2++;}
    while (q2_3.next()){c2_3++;}
    while (q2_4.next()){c2_4++;}
    //total des classes par rapport au type Felonies
    while (q3_1.next()){c3_1++;}
    while (q3_2.next()){c3_2++;}
    while (q3_3.next()){c3_3++;}
    while (q3_4.next()){c3_4++;}


    tot=tot/2;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("A");
            QBarSet *set1 = new QBarSet("B");
            QBarSet *set2 = new QBarSet("C");
            QBarSet *set3 = new QBarSet("D");

            // Assign values for each bar
            *set0 << c1_1<<c2_1<<c3_1;
            *set1 << c1_2<<c2_2<<c3_2;
            *set2 << c1_3<<c2_3<<c3_3;
            *set3 << c1_4<<c2_4<<c3_4;


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
            chart->setTitle("Total des classes par rapport au types");
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTheme( QChart::ChartThemeBlueCerulean);

            QStringList categories;
                categories << "Violation" << "Misdemeanors" << "Felonies" ;
            // Adds categories to the axes
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                    axisX->append(categories);
                    chart->addAxis(axisX, Qt::AlignBottom);
                    series->attachAxis(axisX);

                    QValueAxis *axisY = new QValueAxis();
                    axisY->setRange(0,tot);
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
