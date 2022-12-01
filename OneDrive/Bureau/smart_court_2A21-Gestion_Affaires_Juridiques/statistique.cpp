#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
void statistique::statistique_chart()
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

 //display
   QChartView *chartView=new QChartView(chart,ui->label_stat);
   chartView->setRenderHint(QPainter::Antialiasing);//rendre le donner sur le painter
        chartView->setMinimumSize(900,900);
   chartView->show();
}
