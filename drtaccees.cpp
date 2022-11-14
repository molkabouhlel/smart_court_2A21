#include "drtaccees.h"
#include "ui_drtaccees.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
drtaccees::drtaccees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drtaccees)
{
    ui->setupUi(this);

    ui->id_dr->setValidator(new QIntValidator(0, 99999999, this));
    ui->telephone->setValidator(new QIntValidator(0, 99999999, this));
    ui->salaire->setValidator(new QIntValidator(0,999999999));
    QRegularExpression rx("^[A-Za-z]+$");

        QValidator *validator = new QRegularExpressionValidator(rx, this);
        ui->nom_dr->setValidator(validator);
        ui->prenon_de->setValidator(validator);
        ui->lieu_t->setValidator(validator);
        ui->grade_l->setValidator(validator);
        ui->gender_r->setValidator(validator);


}

drtaccees::~drtaccees()
{
    delete ui;
}
void drtaccees::afficher()
 {
ui->tableView_a->setModel(p.afficher());

 }

void drtaccees::on_ok_dr_clicked()
{
    int id=ui->id_dr->text().toInt();
    QString nom=ui->nom_dr->text();
    QString prenom=ui->prenon_de->text();
    QString date_n=ui->date_n_dr->text();
    QString lieu_t=ui->lieu_t->text();
    int telephone=ui->telephone->text().toInt();
    QString email=ui->email->text();
    float salaire=ui->salaire->text().toFloat();
     QString grade=ui->grade_l->text();
      QString mot_de_passe=ui->mot_dr->text();
       QString gender=ui->gender_r->text();

     QSqlQuery qry;
     qry.prepare("INSERT INTO PERSONNEL (id, nom,prenom,date_n,lieu_t,telephone,email,salaire,grade,mot_de_passe,gender ) "
                   "VALUES (:id, :nom, :prenom, :date_n, :lieu_t, :telephone, :email, :salaire, :grade, :mot_de_passe, :gender )");
     qry.bindValue(":id",id);
      qry.bindValue(":nom", nom);
       qry.bindValue(":prenom", prenom);
        qry.bindValue(":date_n",date_n);
         qry.bindValue(":lieu_t",lieu_t);
     qry.bindValue(":telephone",telephone);
    qry.bindValue(":email",email);
   qry.bindValue(":salaire",salaire);
        qry.bindValue(":grade", grade);
         qry.bindValue(":mot_de_passe", mot_de_passe);
      qry.bindValue(":gender", gender);

    if (qry.exec())
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr(" saved.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("erreur"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void drtaccees::on_modifier_clicked()
{
     QSqlQuery qry;
    int id=ui->id_dr->text().toInt();
    QString nom=ui->nom_dr->text();
    QString prenom=ui->prenon_de->text();
    QString date_n=ui->date_n_dr->text();
    QString lieu_t=ui->lieu_t->text();
    int telephone=ui->telephone->text().toInt();
    QString email=ui->email->text();
    float salaire=ui->salaire->text().toFloat();
     QString grade=ui->grade_l->text();
      QString mot_de_passe=ui->mot_dr->text();
       QString gender=ui->gender_r->text();
       qry.prepare("UPDATE PERSONNEL SET  id=:id, nom=:nom, prenom=:prenom, date_n=:date_n, lieu_t=:lieu_t, telephone=:telephone, email=:email, salaire=:salaire, grade=:grade, mot_de_passe=:mot_de_passe, gender=:gender WHERE id=:id");
       qry.bindValue(":id",id);
       qry.bindValue(":nom", nom);
       qry.bindValue(":prenom", prenom);
        qry.bindValue(":date_n",date_n);
       qry.bindValue(":lieu_t", lieu_t);
       qry.bindValue(":telephone", telephone);
      qry.bindValue(":email",email);
     qry.bindValue(":salaire", salaire);
          qry.bindValue(":grade", grade);
          qry.bindValue(":mot_de_passe", mot_de_passe);
          qry.bindValue(":gender", gender);
          if (qry.exec())
          {
              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr(" modified.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("erreur"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
}
