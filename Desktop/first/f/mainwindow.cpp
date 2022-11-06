#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"juge.h"
#include<QMessageBox>
#include<QMainWindow>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->tV_juge->setModel(Ju.afficher());
    ui->Ejuge_ajouter_cin_2 ->setValidator(new QIntValidator(0, 99999999, this));
    ui->Ejuge_Modiffier_cin_2 ->setValidator(new QIntValidator(0, 99999999, this));
    ui->Ejuge_Modiffier_salaire_2 ->setValidator(new QIntValidator(0, 9999999, this));
    ui->Ejuge_ajoute_salaire_2 ->setValidator(new QIntValidator(0, 9999999, this));
    ui->Ejuge_Modiffier_prenom_2 ->setValidator(new QIntValidator(0, 9999999, this));
    ui->Ejuge_ajouter_ht_2 ->setValidator(new QIntValidator(0,99, this));
    QString HT = QDateTime::currentDateTime().toString(" hh");

    //ui->comboBox->addItems(M2.lister());
    ui->Ejuge_ajouter_nom_2 ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
    ui->Ejuge_ajouter_prenom_2 ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
    ui->Ejuge_Modiffier_nom_2 ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
    ui->Ejuge_Modiffier_prenom_2 ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
}
void MainWindow::on_pB_juge_ajouter_2_clicked()
{
    int cin=ui->Ejuge_ajouter_cin_2->text().toInt();
    QString nom=ui->Ejuge_ajouter_nom_2->text();
    QString prenom=ui->Ejuge_ajouter_prenom_2->text();
    QString salaire=ui->Ejuge_ajoute_salaire_2->text();
    QString Ht=ui->Ejuge_ajouter_ht_2->text();
    QString motpass=ui->Ejuge_ajouter_mpass_2->text();
    QSqlQuery  qry;
    qry.prepare("select * from citoyen where cin='"+motpass+"'");
    if (qry.exec())
    juge J(cin , nom , prenom , Ht , salaire , motpass );
    bool test=Ju.ajouter();
    if(test)
    {
    //ui->tV_juge->setModel(Ju.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajouter effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->Ejuge_ajouter_cin_2->clear();
        ui->Ejuge_ajouter_nom_2->clear();
        ui->Ejuge_ajouter_prenom_2->clear();
        ui->Ejuge_ajoute_salaire_2->clear();
        ui->Ejuge_ajouter_ht_2->clear();
        ui->Ejuge_ajouter_mpass_2->clear();

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajouter non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->Ejuge_ajouter_cin_2->clear();
    ui->Ejuge_ajouter_nom_2->clear();
    ui->Ejuge_ajouter_prenom_2->clear();
    ui->Ejuge_ajoute_salaire_2->clear();
    ui->Ejuge_ajouter_ht_2->clear();
    ui->Ejuge_ajouter_mpass_2->clear();
}

void MainWindow::on_pB_juge_supprimer_2_clicked()
{ //ui->tV_juge->setModel(Ju.afficher());
    juge j1; j1.setCin(ui->Ejuge_suuprimer_cin_2->text().toInt());
        bool test=j1.supprimer(j1.getCin());
        QMessageBox msgBox;
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Suppretion effectuée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->Ejuge_suuprimer_cin_2->clear();


     }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("Suppretion non effectuée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->Ejuge_suuprimer_cin_2->clear();

}

void MainWindow::on_pB_juge_modifier_clicked()
{
    int cin = ui->Ejuge_Modiffier_cin_2->text().toInt();
    QString nom= ui->Ejuge_Modiffier_nom_2->text();
     QString prenom= ui->Ejuge_Modiffier_prenom_2->text();
     QString salaire= ui->Ejuge_Modiffier_salaire_2->text();
     QString Ht= ui->Ejuge_Modiffier_ht_2->text();
     QString motpass= ui->Ejuge_Modiffier_mpaas_2->text();

    juge c(cin,nom,prenom,salaire,Ht,motpass );
    bool test=c.modifier(cin);
   //c.juge();
    if(test)
    {

       // ui->tV_juge->setModel(c.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->Ejuge_Modiffier_cin_2->clear();
               ui->Ejuge_Modiffier_nom_2->clear();
               ui->Ejuge_Modiffier_prenom_2->clear();
               ui->Ejuge_Modiffier_salaire_2->clear();
               ui->Ejuge_Modiffier_ht_2->clear();
               ui->Ejuge_Modiffier_mpaas_2->clear();

   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->Ejuge_Modiffier_cin_2->clear();
        ui->Ejuge_Modiffier_nom_2->clear();
        ui->Ejuge_Modiffier_prenom_2->clear();
        ui->Ejuge_Modiffier_salaire_2->clear();
        ui->Ejuge_Modiffier_ht_2->clear();
        ui->Ejuge_Modiffier_mpaas_2->clear();



    }

}

