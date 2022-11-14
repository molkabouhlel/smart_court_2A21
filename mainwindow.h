#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include<QPainter>
#include<QTextDocument>
#include <QPointF>
#include<QtGlobal>
#include"personnel.h"
#include"statistique.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void statistique();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_chercher_clicked();

    void on_trier_clicked();

    void on_imprimer_clicked();

    void print (QPrinter *printer);

    void on_pdf_clicked();

    void on_login_clicked();

    void on_pushButton_2_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
   Statistique *s ;
};
#endif // MAINWINDOW_H
