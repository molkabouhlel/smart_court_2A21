#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "affaire_juridique.h"
#include <QMessageBox>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Code->setValidator( new QIntValidator(0, 99999999, this));
    ui->Nom->setMaxLength(10);
    ui->cause->setMaxLength(10);


    ui->Affichage->setModel(A.afficher());
    /*for(int i=0;i<2;i++)
    ui->Affichage->setIndexWidget(ui->Affichage->model()->index(i, 7),ui->groupBox);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_done_clicked() //Ajouter
{
    int  code=ui->Code->text().toInt() ;
    QString nom=ui->Nom->text();
    QString date=ui->date->text();
    QString cause=ui->cause->text();
    QString type=ui->type->currentText();
    QString classe=ui->classe->currentText();
    QString description=ui->description->toPlainText();
    //option
    Affaire_juridique A(nom,code,date,cause,type,classe,description);
    bool test=A.ajouter();
    if(test)
    {
        ui->Affichage->setModel(A.afficher());
        //ui->Affichage->setIndexWidget(ui->Affichage->model()->index(1, 7),ui->delete_2);
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_delete_2_clicked() //clicked on trash
{

}


void MainWindow::on_supprimer_clicked() //clicked on "supprimer"
{
    int  code_supp=ui->Code_supp->text().toInt();
    QString nom_supp=ui->Nom_supp->text();
    bool test=A.supprimer(code_supp,nom_supp);
    if(test)
     {
        ui->Affichage->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_Modifier_clicked()
{
bool test=false;
    int  code_mod=ui->Code_mod->text().toInt();

    QString nom=ui->Nom->text();
    QString date=ui->date->text();
    QString cause=ui->cause->text();
    QString type=ui->type->currentText();
    QString classe=ui->classe->currentText();
    QString description=ui->description->toPlainText();

    Affaire_juridique A(nom,code_mod,date,cause,type,classe,description);
    test=A.modifier(code_mod);

    if(test)
     {
        ui->Affichage->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modification effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("modification non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
