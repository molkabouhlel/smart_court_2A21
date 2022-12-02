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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include<QPrintDialog>
#include <QMessageBox>
#include <QFileDialog>
#include<QDebug>
#include <QDateTime>
#include <QDate>
#include"excel.h"
#include "affaire_juridique.h"
#include "mapping.h"
#include "calendrier.h"
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
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //PARTIE MOLKA
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


    //PARTIE AMINE
   // ui->setupUi(this);
    //controle de saisie code
    ui->Code_A->setValidator( new QIntValidator(0, 99999999, this));

    //controle de saisie nom
    ui->Nom_A->setMaxLength(10);
    QRegularExpression nom("^[A-Za-z]+$");
    QValidator *validator_nom = new QRegularExpressionValidator(nom, this);
    ui->Nom_A->setValidator(validator_nom);

    //controle de saisie cause
    ui->cause_A->setMaxLength(10);
    QRegularExpression cause("^[A-Za-z]+$");
    QValidator *validator_cause = new QRegularExpressionValidator(cause, this);
    ui->cause_A->setValidator(validator_cause);

    ui->nbr_pr->setValidator(new QIntValidator(100,500, this));
    ui->tableView->setModel(a.afficher());
    QTextCharFormat format = ui->calendarWidgett->weekdayTextFormat(Qt::Saturday);
       format.setForeground(QBrush(Qt::black, Qt::SolidPattern));
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Saturday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Sunday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Monday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Tuesday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Wednesday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Thursday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Friday, format);
       QDateTime cdt = QDateTime::currentDateTime();
          ui->dateEdit->setDateTime(cdt);
ui->dateEdit_2->setDateTime(cdt);
//stat
       QChart *chart = new QChart();

            chart=a.stat();

           QChartView *chartview = new QChartView(chart,ui->widget);

           chartview->resize(400,300);

           chartview->setRenderHint(QPainter::Antialiasing);
    ui->Affichage_A->setModel(A.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

//***********************************MOLKA*******************************************
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
               query.prepare("select * from personnels");
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





//***********************************AMINE*******************************************
void Dialog::on_done_2_clicked() //Ajouter
{

    int code=ui->Code_A->text().toInt() ;
    QString nom=ui->Nom_A->text();
    QDateTime  date=ui->date_A->dateTime();
    QString cause=ui->cause_A->text();
    QString type=ui->type_A->currentText();
    QString classe=ui->classe_A->currentText();
    QString description=ui->description_A->toPlainText();
    //option

    Affaire_juridique A(nom,code,date,cause,type,classe,description);
    bool test=A.ajouter();

    if(test)
    {
        ui->Affichage_A->setModel(A.afficher());
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


void Dialog::on_supprimer_A_clicked() //clicked on "supprimer"
{
    int  code_supp=ui->Code_supp_A->text().toInt();
    QString nom_supp=ui->Nom_supp_A->text();
    bool test=A.supprimer(code_supp,nom_supp);
    if(test)
     {
        ui->Affichage_A->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Dialog::on_Modifier_A_clicked()//Modifier
{
bool test=false;
    int  code_mod=ui->Code_mod_A->text().toInt();

    QString nom=ui->Nom_A->text();
    QDateTime  date=ui->date_A->dateTime();
    QString cause=ui->cause_A->text();
    QString type=ui->type_A->currentText();
    QString classe=ui->classe_A->currentText();
    QString description=ui->description_A->toPlainText();

    Affaire_juridique A(nom,code_mod,date,cause,type,classe,description);
    test=A.modifier(code_mod);

    if(test)
     {
        ui->Affichage_A->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modification effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("modification non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_Affichage_A_clicked(const QModelIndex &index)//Selectioner
{
    ui->Code_A->setText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),0)).toString());
    ui->Nom_A->setText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),1)).toString());
    ui->type_A->setCurrentText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),2)).toString());
    ui->date_A->setDateTime(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),3)).toDateTime());
    ui->classe_A->setCurrentText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),4)).toString());
    ui->description_A->setPlainText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),5)).toString());
    ui->cause_A->setText(ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(index.row(),6)).toString());


    QString text =" code:"+ ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),0)).toString()
                  +"nom: "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),1)).toString()
                  +"type: "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),2)).toString()
                  +"date: "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),3)).toString()
                  +"classe: "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),4)).toString()
                  +"description: "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),5)).toString();
                  +"cause "+ui->Affichage_A->model()->data(ui->Affichage_A->model()->index(ui->Affichage_A->currentIndex().row(),6)).toString();

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
            ui->qrcode_3->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );

}

void Dialog::on_Recherche_2_clicked()//Chercher
{
QString chercherbox=ui->chercherbox_A->currentText();

if (chercherbox == "par defaut")
 {
 QString nom_recherche=ui->recherche_2->text();
 ui->Affichage_A->setModel(A.recherchepardefaut(nom_recherche));
 }
else if(chercherbox == "par classe")
 {
 QString classe_recherche=ui->recherche_2->text();
 ui->Affichage_A->setModel(A.rechercheparclasse(classe_recherche));
 }
else if (chercherbox == "par type")
 {
 QString type_recherche=ui->recherche_2->text();
 ui->Affichage_A->setModel(A.recherchepartype(type_recherche));
 }
}

void Dialog::on_refresh_A_clicked()//Actualiser
{
ui->Affichage_A->setModel(A.afficher());
}

void Dialog::on_trier_A_clicked()//TRI
{

    QString tribox=ui->tri_A->currentText();

    if (tribox == "par defaut")
     {
     ui->Affichage_A->setModel(A.TRIpardefaut());
     }
    else if(tribox == "par classe")
     {
     ui->Affichage_A->setModel(A.TRIparclasse());
     }
    else if (tribox == "par date")
     {
     ui->Affichage_A->setModel(A.TRIpardate());
     }
}


/*
void Dialog::choix_bar()
{
    s = new statistique();

    s->setWindowTitle("statistique ComboBox");
    //s->choix_bar();
    s->show();

}*/


void Dialog::on_pdf_A_clicked()
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

void Dialog::on_stat_A_clicked()
{
    s = new statistique();

    s->setWindowTitle("statistique des affaires juridiques");
    s->choix_bar();
    s->show();
}

void Dialog::on_location_A_clicked()
{

    l = new localisation();

    l->setWindowTitle("Map");
    l->map();
    l->show();


}


//*************************SARRA****************************//




void Dialog::on_ajout_clicked()
{
    QString id_r=ui->id->text();
    QString type_r=ui->comboBox_2->currentText();
    QString date_d=ui->dateEdit->text();
    QString date_f=ui->dateEdit_2->text();
    QString local=ui->local->text();
    int nb_per=ui->nbr_pr->text().toInt();
    Calendrier c(id_r,date_d,date_f,local, nb_per,type_r);
    bool test =c.ajouter();
    if(test)
    {
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->id->setText("");

        ui->local->setText("");
        ui->nbr_pr->setText("");
         QDateTime cdt = QDateTime::currentDateTime();
        ui->dateEdit->setDateTime(cdt);
ui->dateEdit_2->setDateTime(cdt);


}
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    QChart *chart = new QChart();

         chart=a.stat();

        QChartView *chartview = new QChartView(chart,ui->widget);

        chartview->resize(400,300);

        chartview->setRenderHint(QPainter::Antialiasing);
}

void Dialog::on_supp_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
      QString id_r = index.data(Qt::DisplayRole).toString();
      QTextCharFormat formattt ;
      QDate datet;
          formattt.setForeground(QBrush(Qt::black, Qt::SolidPattern));


    bool test =a.supprimer(id_r);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView->setModel(a.afficher());
 ui->calendarWidgett->setDateTextFormat(datet, formattt);
 QChart *chart = new QChart();

      chart=a.stat();

     QChartView *chartview = new QChartView(chart,ui->widget);

     chartview->resize(400,300);

     chartview->setRenderHint(QPainter::Antialiasing);
}
    else{

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}



void Dialog::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->tableView->setModel(a.rechercher(arg1));

}

void Dialog::on_trie_clicked()
{QString trie=ui->comboBox->currentText();
    if(trie=="DATE"){
         ui->tableView->setModel(a.AfficherTri());}
       else if(trie=="ID"){
          ui->tableView->setModel(a.AfficherTriid());
       }
       else if(trie=="TYPE"){
          ui->tableView->setModel(a.AfficherTritype());
       }
}




//pdf

void Dialog::on_pushButton_5_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView->model()->rowCount();
                            const int columnCount = ui->tableView->model()->columnCount();

                            out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("strTitle")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"

                               //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H1> SmartCourt \n \n\n\n</H1><H2>Liste des rendez_vous \n \n\n\n</H2><H3> \n \n\n\n</H3></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


                            // headers
                            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView->isColumnHidden(column)) {
                                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table> </center>\n"
                                "</body>\n"
                                "</html>\n";

                      QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}
//export excel
void Dialog::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                tr("Excel Files (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "rendez_vous", ui->tableView);

                //colums to export
                obj.addField(0, "ID_R", "char(20)");
                obj.addField(1, "DATE_D", "char(20)");
                obj.addField(2, "DATE_F", "char(20)");
                obj.addField(3, "TYPE_R", "char(20)");
                obj.addField(4, "NB_PER", "NUMBER");
                obj.addField(5, "LOCAL", "char(20)");





                int retVal = obj.export2Excel();
                if( retVal > 0)
                {
                    QString text = "Archivé avec success!";
                    QString titre = "Archivage complete!";

                }
}









//charger
void Dialog::on_pushButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
                QString id_r = index.data(Qt::DisplayRole).toString();
                QString nbr = ui->tableView->model()->index(index.row(), 4).data(Qt::DisplayRole).toString();
                ui->nbr_pr->setText(nbr);
                QString type = ui->tableView->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
                ui->comboBox_2->setCurrentText(type);

                //QString date = ui->tableView->model()->index(index.row(), 1).data(Qt::DisplayRole).toDateTime();
                ui->dateEdit_2->setDate(ui->tableView->model()->index(index.row(), 2).data(Qt::DisplayRole).toDate());
                  ui->dateEdit->setDate(ui->tableView->model()->index(index.row(), 1).data(Qt::DisplayRole).toDate());

                QString id = ui->tableView->model()->index(index.row(), 0).data(Qt::DisplayRole).toString();
                ui->id->setText(id);
                QString local = ui->tableView->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
                ui->local->setText(local);
}

void Dialog::on_tabWidget_currentChanged(int index)
{
    QDate datet;
       QSqlQuery qry;
       QTextCharFormat formattt ;
       formattt.setForeground(QBrush(Qt::white, Qt::SolidPattern));

       qry.prepare("select DATE_D from CALENDRIER");
       if(qry.exec())
       {
           while(qry.next())
           {
               datet=qry.value(1).toDate();
               ui->calendarWidgett->setDateTextFormat(datet, formattt);


           }
       }
}
//caledrier
void Dialog::on_calendarWidgett_clicked(const QDate &date)
{
    ui->dateEdit_3->setDate(date);
    QString aa=ui->dateEdit_3->text();


       QSqlQuery qry;


       qry.prepare("select * from CALENDRIER ");

       if(qry.exec())
       {
           while(qry.next())
           {
               //Remplir tous les champs par les données concernées

   if(qry.value(1).toString()==aa)
   {
               ui->lineEdit->setText(qry.value(1).toString());
               ui->lineEdit_3->setText(qry.value(3).toString());
               ui->lineEdit_2->setText(qry.value(5).toString());
               ui->lineEdit_7->setText(qry.value(2).toString());
               ui->lineEdit_4->setText(qry.value(4).toString());

       ui->lineEdit_6->setText(qry.value(0).toString());


   }

   }//fin while
   }//fin if qry
}




void Dialog::on_modifier_2_clicked()
{

    QString id=ui->id->text();
    QString type_r=ui->comboBox_2->currentText();
    QString date_d=ui->dateEdit->text();
    QString date_f=ui->dateEdit_2->text();
    QString local=ui->local->text();
    int nb_per=ui->nbr_pr->text().toInt();




    Calendrier d (id,date_d,date_f,local, nb_per,type_r);
    if(d.modifiers(id))
    {
             QMessageBox::information(nullptr, QObject::tr("Modifier un calendrier"),
                         QObject::tr("calendrier modifié.\n"), QMessageBox::Cancel);
             ui->tableView->setModel(a.afficher());

              QChart *chart = new QChart();

                   chart=a.stat();

                  QChartView *chartview = new QChartView(chart,ui->widget);

                  chartview->resize(400,300);

                  chartview->setRenderHint(QPainter::Antialiasing);
                  ui->id->setText("");

                  ui->local->setText("");
                  ui->nbr_pr->setText("");
                  QDateTime cdt = QDateTime::currentDateTime();
                 ui->dateEdit->setDateTime(cdt);
         ui->dateEdit_2->setDateTime(cdt);




    }
    else
    {
       QMessageBox::critical(nullptr, QObject::tr("Modifier un calendrier"),

                             QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);

    }
}
