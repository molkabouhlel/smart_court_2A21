#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "suspet.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QMainWindow>
#include <QIntValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator (new QIntValidator(0, 99999999, this));
    ui->n1->setValidator (new QIntValidator(0, 99999999, this));
    ui->n2->setValidator (new QIntValidator(0, 99999999, this));
    QRegularExpression rx("^[A-Za-z]+$");

        QValidator *validator = new QRegularExpressionValidator(rx, this);
        ui->nom->setValidator(validator);
        ui->prenom->setValidator(validator);
        ui->case_id->setValidator(validator);
        ui->adresseaj->setValidator(validator);

    ui->afficher->setModel(s.afficher());




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_supp_clicked()
{
    Suspet s1;
    s1.setID(ui->sup->text().toInt());
    bool test1;
    test1 =s1.supprimer(s1.getID());
    if(test1)
    {
        ui->afficher->setModel(s.afficher());

        QMessageBox::information(nullptr, QObject::tr("SUPP effuctué"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supp n'est pas effuctué"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_ajout_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse = ui->adresseaj->text();
    QString case_id=ui->case_id->text();
    int n1=ui->n1->text().toInt();
    int n2=ui->n2->text().toInt();
    QDate date=ui->dateEdit->date();
    Suspet s( id,nom,prenom,adresse,date,case_id,n1,n2);
    bool test=s.ajouter();
    if(test)
    {
        ui->afficher->setModel(s.afficher());

        QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_afficher_activated(const QModelIndex &index)
{
    QString val=ui->afficher->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from SUSPET where id='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->prenom->setText(qry.value(2).toString());
            ui->adresseaj->setText(qry.value(3).toString());
            ui->dateEdit->setDate(qry.value(4).toDate());
            ui->case_id->setText(qry.value(5).toString());
            ui->n1->setText(qry.value(6).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctué"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifier_clicked()
{
    int id=ui->id->text().toInt();
    int n1=ui->n1->text().toInt();
    int n2=ui->n2->text().toInt();

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse = ui->adresseaj->text();
    QString case_id=ui->case_id->text();
    //QDate date=ui->dateEdit->date();
    QString cin= QString::number(id);
    QString num1= QString::number(n1);
    QString num2= QString::number(n2);


    QSqlQuery quer;
    quer.prepare("update SUSPET set id='"+cin+"', nom='"+nom+"', adresse='"+adresse+"',  case_id='"+case_id+"', numero1='"+num1+"'where id='"+id+"'");
    if(quer.exec())
    {

        ui->afficher->setModel(s.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                              QObject::tr("modification non effectué \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}
