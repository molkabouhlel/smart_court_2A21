#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "affaire_juridique.h"
#include "mapping.h"


#include <QMessageBox>
#include <QIntValidator>

#include<QPrinter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>

#include "qrcode.cpp"


QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //controle de saisie code
    ui->Code->setValidator( new QIntValidator(0, 99999999, this));

    //controle de saisie nom
    ui->Nom->setMaxLength(10);
    QRegularExpression nom("^[A-Za-z]+$");
    QValidator *validator_nom = new QRegularExpressionValidator(nom, this);
    ui->Nom->setValidator(validator_nom);

    //controle de saisie cause
    ui->cause->setMaxLength(10);
    QRegularExpression cause("^[A-Za-z]+$");
    QValidator *validator_cause = new QRegularExpressionValidator(cause, this);
    ui->cause->setValidator(validator_cause);


    ui->Affichage->setModel(A.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_done_clicked() //Ajouter
{

    int code=ui->Code->text().toInt() ;
    QString nom=ui->Nom->text();
    QDateTime  date=ui->date->dateTime();
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


void MainWindow::on_Modifier_clicked()//Modifier
{
bool test=false;
    int  code_mod=ui->Code_mod->text().toInt();

    QString nom=ui->Nom->text();
    QDateTime  date=ui->date->dateTime();
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

void MainWindow::on_Affichage_clicked(const QModelIndex &index)//Selectioner
{
    ui->Code->setText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),0)).toString());
    ui->Nom->setText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),1)).toString());
    ui->type->setCurrentText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),2)).toString());
    ui->date->setDateTime(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),3)).toDateTime());
    ui->classe->setCurrentText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),4)).toString());
    ui->description->setPlainText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),5)).toString());
    ui->cause->setText(ui->Affichage->model()->data(ui->Affichage->model()->index(index.row(),6)).toString());


    QString text ="dossier medicale details :"+ ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),0)).toString()
                  +"code "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),1)).toString()
                  +" "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),2)).toString()
                  +" "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),3)).toString()
                  +" "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),4)).toString()
                  +" "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),5)).toString();
                  +" "+ui->Affichage->model()->data(ui->Affichage->model()->index(ui->Affichage->currentIndex().row(),5)).toString();
          //text="user data";
          using namespace qrcodegen;
            // Create the QR Code object
            QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
            qint32 sz = qr.getSize();
            QImage im(sz,sz, QImage::Format_RGB32);
              QRgb black = qRgb(  0,  0,  0);
              QRgb white = qRgb(255,255,255);
            for (int y = 0; y < sz; y++)
              for (int x = 0; x < sz; x++)
                im.setPixel(x,y,qr.getModule(x, y) ? black : white );
            ui->qrcode_2->setPixmap( QPixmap::fromImage(im.scaled(150,150,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );


}

void MainWindow::on_Recherche_clicked()//Chercher
{
QString chercherbox=ui->chercherbox->currentText();

if (chercherbox == "par defaut")
 {
 QString nom_recherche=ui->recherche->text();
 ui->Affichage->setModel(A.recherchepardefaut(nom_recherche));
 }
else if(chercherbox == "par classe")
 {
 QString classe_recherche=ui->recherche->text();
 ui->Affichage->setModel(A.rechercheparclasse(classe_recherche));
 }
else if (chercherbox == "par type")
 {
 QString type_recherche=ui->recherche->text();
 ui->Affichage->setModel(A.recherchepartype(type_recherche));
 }
}

void MainWindow::on_refresh_clicked()//Actualiser
{
ui->Affichage->setModel(A.afficher());
}

void MainWindow::on_trier_clicked()//TRI
{

    QString tribox=ui->tri->currentText();

    if (tribox == "par defaut")
     {
     ui->Affichage->setModel(A.TRIpardefaut());
     }
    else if(tribox == "par classe")
     {
     ui->Affichage->setModel(A.TRIparclasse());
     }
    else if (tribox == "par date")
     {
     ui->Affichage->setModel(A.TRIpardate());
     }
}



void MainWindow::choix_bar()
{
    s = new statistique();

    s->setWindowTitle("statistique ComboBox");
    s->choix_bar();
    s->show();

}


void MainWindow::on_pdf_clicked()
{


    QString ach=".pdf";
        QPdfWriter pdf("C:/Users/thebe/OneDrive/Bureau/SmartCourt"+ach);


                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Impact", 30));
                              painter.drawText(2200,1400,"Liste des affaires juridiques ");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("impact", 50));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("impact", 11));
                              painter.drawText(200,3300,"Code");
                              painter.drawText(1200,3300,"Nom");
                              painter.drawText(2400,3300,"type");
                              painter.drawText(4400,3300,"date");
                              painter.drawText(5900,3300,"classe");
                              painter.drawText(6900,3300,"desctiption");
                              painter.drawText(8400,3300,"cause");



                              QSqlQuery query;
                              query.prepare("select * from AFFAIRES_JURIDIQUES");
                              query.exec();
                              painter.setFont(QFont("Arial",9));
                              while (query.next())
                              {
                                  painter.drawText(200,i,query.value(0).toString());
                                  painter.drawText(1200,i,query.value(1).toString());
                                  painter.drawText(2400,i,query.value(2).toString());
                                  painter.drawText(4000,i,query.value(3).toString());
                                  painter.drawText(6000,i,query.value(4).toString());
                                  painter.drawText(7000,i,query.value(5).toString());
                                  painter.drawText(8400,i,query.value(6).toString());



                                 i = i + 500;
                              }
                              painter.drawRect(0,3000,9600,i-3000);
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/thebe/OneDrive/Bureau/SmartCourt"+ach));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }


}

void MainWindow::on_stat_clicked()
{
    s = new statistique();

    s->setWindowTitle("statistique des affaires juridiques");
    s->choix_bar();
    s->show();
}

void MainWindow::on_location_clicked()
{

    l = new localisation();

    l->setWindowTitle("Map");
    l->map();
    l->show();


}

