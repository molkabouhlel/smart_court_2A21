#include "dialog.h"
#include "ui_dialog.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include "personnel.h"
#include<QObject>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->l_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_tele->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_salaire->setValidator(new QIntValidator(0,999999999));
        QRegularExpression rx("^[A-Za-z]+$");

            QValidator *validator = new QRegularExpressionValidator(rx, this);
            ui->l_nom->setValidator(validator);
            ui->l_prenom->setValidator(validator);
            ui->l_lieu_t->setValidator(validator);
            ui->l_grade->setValidator(validator);
            ui->l_gender_2->setValidator(validator);

    ui->afficher_t->setModel(p.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_chercher_clicked()
{
    Personnel p;
    int id = ui->l_id->text().toInt();
     ui->afficher_t->setModel(p.chercher(id));
}

void Dialog::on_ajouter_clicked()
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
        QString mot_de_passe=ui->motpasse_l->text();
        QString gender=ui->l_gender_2->text();
    Personnel p( id,nom,prenom,date_n,lieu_t,telephone,email,salaire,grade,mot_de_passe,gender);
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

void Dialog::on_modifier_clicked()
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
        QString mot_de_passe=ui->motpasse_l->text();
        QString gender=ui->l_gender_2->text();
         Personnel p2( id,nom,prenom,date_n,lieu_t,telephone,email,salaire,grade,mot_de_passe,gender );
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

void Dialog::on_supprimer_clicked()
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

void Dialog::on_pushButton_2_clicked()
{
    QPdfWriter pdf("C:/Users/molka/OneDrive/Bureau/Doc1.pdf");
       QPainter painter(&pdf);

           int i = 4000;
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial", 30));
               painter.drawText(1100,1200,"List des personnels");
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial", 15));

               painter.drawRect(100,100,9200,2600);//drawRect (x1, y1, w, h
               painter.drawRect(0,3000,9600,500);// mta3 titre
               painter.setFont(QFont("Arial", 9));
               painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/molka/OneDrive/Bureau/ligne-icône-de-carte-d-identification-99265830.jpg"));
               painter.drawText(200,3300,"ID");
               painter.drawText(1300,3300,"nom");
               painter.drawText(2100,3300,"prenom");
               painter.drawText(3200,3300,"date_n");
               painter.drawText(4500,3300,"lieu_t");
               painter.drawText(5400,3300,"telephone");
               painter.drawText(6400,3300,"email");
               painter.drawText(7400,3300,"salaire");
               painter.drawText(8400,3300,"grade");
               QSqlQuery query;
               query.prepare("select * from personnel");
               query.exec();
               while (query.next())
               {
                   painter.drawText(200,i,query.value(0).toString());
                   painter.drawText(1300,i,query.value(1).toString());
                   painter.drawText(2200,i,query.value(2).toString());
                   painter.drawText(3200,i,query.value(3).toString());
                   painter.drawText(4500,i,query.value(4).toString());
                   painter.drawText(5400,i,query.value(5).toString());
                   painter.drawText(6400,i,query.value(6).toString());
                   painter.drawText(7400,i,query.value(7).toString());
                   painter.drawText(8400,i,query.value(8).toString());
                 i = i + 500;
               }
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {

                       painter.end();
                   }
                   if (reponse == QMessageBox::No)
                   {
                        painter.end();
                   }
}

void Dialog::on_stat_clicked()
{
    s = new statistique();

  s->setWindowTitle("statistique");
  s->statistique_chart();
  s->show();
}

void Dialog::on_trier_clicked()
{
    Personnel p;
         if (ui->trierecher->currentText()=="id")
         {
             ui->trierecher->clear();
         ui->afficher_t->setModel(p.tri_id());
         }
         else if (ui->trierecher->currentText()=="nom")
         {
             ui->afficher_t->setModel(p.tri_nom());
         }
         else if(ui->trierecher->currentText()=="salaire")
         {
           ui->afficher_t->setModel(p.tri_salaire());
          }
}
