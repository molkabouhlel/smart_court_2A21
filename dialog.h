#ifndef DIALOG_H
#define DIALOG_H
//molka
#include <QDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include<QPainter>
#include<QTextDocument>
#include <QPointF>
#include<QtGlobal>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "personnel.h"
#include"statistique.h"
#include <QDialog>


//amine
#include "affaire_juridique.h"
#include "statistique.h"
#include "localisation.h"
#include "mapping.h"

#include <QChart>
#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QValueAxis>
#include <QWidget>


//sarra
#include"calendrier.h"
#include <QMainWindow>
#include <QtCharts>
#include<QCalendarWidget>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    //PARTIE MOLKA
    void on_chercher_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_stat_clicked();

    void on_trier_clicked();


    //PARTIE AMINE
    void on_done_2_clicked();

        void on_supprimer_A_clicked();

        void on_Modifier_A_clicked();

        void on_Affichage_A_clicked(const QModelIndex &index);

        void on_Recherche_2_clicked();

        void on_refresh_A_clicked();

        void on_trier_A_clicked();

        void on_pdf_A_clicked();

        void on_stat_A_clicked();

        void on_location_A_clicked();


        //PARTIE SARRA
        void on_ajout_clicked();

        void on_supp_clicked();

        //void on_modifier_clicked();

        void on_lineEdit_5_textChanged(const QString &arg1);

        void on_trie_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_calendarWidgett_clicked(const QDate &date);

        void on_pushButton_clicked();



        void on_tabWidget_currentChanged(int index);




        void on_modifier_2_clicked();

private:
    Ui::Dialog *ui;
    Personnel p;
     statistique *s;


     Affaire_juridique A;
     QChartView *chartView ;
     WebAxWidget  WebAxWidget;
     localisation *l;
     Calendrier a;

};

#endif // DIALOG_H
