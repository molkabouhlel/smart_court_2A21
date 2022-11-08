#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <salle.h>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_num_salle->setValidator (new QIntValidator(0, 20, this));
    ui->tab_salle->setModel(S.afficher());


    ui->le_etage->setValidator (new QIntValidator(0, 10, this));

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
     QString departement=ui->le_departement->currentText();
     QString juge=ui->le_juge->currentText();
      QString suspect=ui->le_suspect->text();
    int etage=ui->le_etage->currentIndex();

QString num_salle_string= QString::number(num_salle);

    if(S.existance(num_salle_string))
        {

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
}



void MainWindow::on_pb_modif_clicked()
{
    int num_salle=ui->le_num_salle->text().toInt();
    QString departement=ui->le_departement->currentText();
    int etage=ui->le_etage->currentIndex();
    QString juge=ui->le_juge->currentText();

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

void MainWindow::on_pb_rechercher_clicked()

    {
        int num_salle=ui->le_rechercher->text().toInt();
        QString cin= QString::number(num_salle);
        if(num_salle!=0)
            ui->tab_recherche->setModel(S.recherche(cin));
        else
            ui->tab_recherche->setModel(S.afficher());



}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="num de salle")
           ui->tab_recherche->setModel(S.trier(3));
       else  if(arg1=="etage")
           ui->tab_recherche->setModel(S.trier(2));
       else  if(arg1=="departement")
           ui->tab_recherche->setModel(S.trier(1));
}







/*void MainWindow::on_PDF_clicked()
{
 S.pdf();

}*/
void MainWindow::on_PDF_clicked()
{
    {
        QSqlQuery query;
    query.prepare("select * from SALLE where NUM_SALLE");
     S.telechargerPDF();
        if(query.exec()){

            while(query.next())
            {

             //B.telechargerPDF(val);
            ui->le_num_salle->setText(query.value(0).toString());
            ui->le_etage->setCurrentText(query.value(1).toString());
            ui->le_departement->setCurrentText(query.value(2).toString());
            ui->le_juge->setCurrentText(query.value(3).toString());
            ui->le_suspect->setText(query.value(4).toString());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);




      }
        }
        else
            QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }

}

