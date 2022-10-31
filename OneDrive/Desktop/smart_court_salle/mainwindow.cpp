#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <salle.h>
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_num_salle->setValidator (new QIntValidator(0, 10, this));
    ui->tab_salle->setModel(S.afficher());


    ui->le_etage->setValidator (new QIntValidator(0, 20, this));

        QRegularExpression rx("^[A-Za-z]+$");

            QValidator *validator = new QRegularExpressionValidator(rx, this);
            ui->le_departement->setValidator(validator);
            ui->le_juge->setValidator(validator);
            ui->le_suspect->setValidator(validator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int num_salle=ui->le_num_salle->text().toInt();
     QString departement=ui->le_departement->text();
     QString juge=ui->le_juge->text();
      QString suspect=ui->le_suspect->text();
    int etage=ui->le_etage->text().toInt();





    Salle S(num_salle,departement,etage,juge,suspect);
bool test=S.ajouter();
 if(test)
 {    ui->tab_salle->setModel(S.afficher());
     QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("ajout effectue.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr("ajout non effectue.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_pb_modif_clicked()
{
    int num_salle=ui->le_num_salle->text().toInt();
    QString departement=ui->le_departement->text();
    int etage=ui->le_etage->text().toInt();
    QString juge=ui->le_juge->text();
    QString suspect=ui->le_suspect->text();

      Salle S(num_salle,departement,etage,juge,suspect);
    bool test=S.modifier();

        if(test){
            ui->tab_salle->setModel(S.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("modification effectuée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_supprimer_clicked()
{
    int num_salle=ui->le_num_salle_supp->text().toInt();
    bool test=S.supprimer(num_salle);

    if (test)
    {
        ui->tab_salle->setModel(S.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("suppression effectuée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("suppression failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
