#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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



QT_CHARTS_USE_NAMESPACE

namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void choix_bar();

private slots:

    void on_done_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

    void on_Affichage_clicked(const QModelIndex &index);

    void on_Recherche_clicked();

    void on_refresh_clicked();

    void on_trier_clicked();

    void on_pdf_clicked();

    void on_stat_clicked();

    void on_location_clicked();


private:
    Ui::MainWindow *ui;
    Affaire_juridique A;
    QChartView *chartView ;
    WebAxWidget  WebAxWidget;
    statistique *s;
    localisation *l;
};



#endif // MAINWINDOW_H
