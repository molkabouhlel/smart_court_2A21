#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include "personnel.h"
#include <QMessageBox>
#include<QObject>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui ->setupUi(this);
    ui->l_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_tele->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_salaire->setValidator(new QIntValidator(0,999999999));
    ui->afficher_t->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int id=ui->l_id->text().toInt();
    QString nom=ui->l_nom->text();
     QString prenom=ui->l_prenom->text();
    QString date_n=ui->l_date->text();
      QString lieu_t=ui->l_lieu_t->text();
     int telephone =ui->l_tele->text().toInt();
         QString email=ui->l_email->text();
         float salaire=ui->l_salaire->text().toFloat();
        QString grade=ui->l_grade->text();
    Personnel p( id,nom,prenom,date_n,lieu_t,telephone,email,salaire,grade );
bool test=p.ajouter();
if (test)
{
    ui->afficher_t->setModel(p.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr(" ajout effectue.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                QObject::tr(" ajout non  effectue.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_supprimer_clicked()
{
    Personnel p1;p1.setid(ui->l_id->text().toInt());
    bool test;
    test =p1.supprimer(p1.getid());
    if (test)
    {
        ui->afficher_t->setModel(p1.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr(" suppression effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr(" suppression non  effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifier_clicked()
{
    int id=ui->l_id->text().toInt();
    QString nom=ui->l_nom->text();
     QString prenom=ui->l_prenom->text();
    QString date_n=ui->l_date->text();
      QString lieu_t=ui->l_lieu_t->text();
     int telephone =ui->l_tele->text().toInt();
         QString email=ui->l_email->text();
         float salaire=ui->l_salaire->text().toInt();
        QString grade=ui->l_grade->text();
         Personnel p2( id,nom,prenom,date_n,lieu_t,telephone,email,salaire,grade );
         bool test=p2.modifier();
         if (test)
         {
             ui->afficher_t->setModel(p2.afficher());
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr(" modification effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                         QObject::tr(" modification non  effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }

}
