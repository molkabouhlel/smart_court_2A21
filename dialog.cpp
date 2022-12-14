#include "dialog.h"
#include "ui_dialog.h"
QT_CHARTS_USE_NAMESPACE
Dialog::Dialog(QWidget *parent) : QDialog(parent),  ui(new Ui::Dialog)
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
    QChart *chartpersonnel = new QChart();

         chartpersonnel=p.statistique_chart();

        QChartView *chartviewpersonnel = new QChartView(chartpersonnel,ui->widget_3);

        chartviewpersonnel->resize(500,250);

        chartviewpersonnel->setRenderHint(QPainter::Antialiasing);


    //PARTIE AMINE
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
    ui->Affichage_A->setModel(A.afficher());
    //stat
    QChart *chartaffaire = new QChart();

         chartaffaire=A.statAffaire();

        QChartView *chartviewaffaire = new QChartView(chartaffaire,ui->widget_2);

        chartviewaffaire->resize(400,250);

        chartviewaffaire->setRenderHint(QPainter::Antialiasing);


    //PARTIE SARRA
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

           chartview->resize(300,250);

           chartview->setRenderHint(QPainter::Antialiasing);


           //PARTIE ONS
           ui->le_num_salle->setValidator (new QIntValidator(0, 20, this));
           ui->tab_salle->setModel(S.afficher());


           ui->le_etage->setValidator (new QIntValidator(0, 10, this));

               QRegularExpression rxx("^[A-Za-z]+$");

                   QValidator *validatorr = new QRegularExpressionValidator(rxx, this);
                   ui->le_departement->setValidator(validatorr);
                   ui->le_juge->setValidator(validatorr);
                   ui->le_suspect->setValidator(validatorr);

                    /////////PARTIE CHEDLY
                   ui->ll->hide();
                   ui->ls->hide();

                   ui->id->setValidator (new QIntValidator(0, 99999999, this));
                   ui->n1->setValidator (new QIntValidator(0, 99999999, this));
                   ui->n2->setValidator (new QIntValidator(0, 99999999, this));
                   QRegularExpression rxxxx("^[A-Za-z]+$");
                   QValidator *valida = new QRegularExpressionValidator(rxxxx, this);

                   ui->nom->setValidator(valida);
                   ui->prenom->setValidator(valida);
                   ui->adresseaj->setValidator(valida);
                   QRegularExpression regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
                   QValidator *val = new QRegularExpressionValidator(regex, this);
                   ui->mail->setValidator(val);
                   ui->afficher->setModel(s.afficher());
                   ui->comboBox->addItem("date d'ajout") ;
                   ui->comboBox->addItem("id") ;
                   ui->comboBox->addItem("date de naissance");
                   ui->comboBox->addItem("nom");
                   int ret=ard.connect_arduino(); // lancer la connexion ?? arduino
                   switch(ret){
                   case(0):qDebug()<< "arduino is available and connected to : "<< ard.getarduino_port_name();
                       break;
                   case(1):qDebug() << "arduino is available but not connected to :" <<ard.getarduino_port_name();
                      break;
                   case(-1):qDebug() << "arduino is not available";
                   }
                    QObject::connect(ard.getserial(),SIGNAL(readyRead()),this,SLOT(update())); // permet de lancer
                    //le slot update_label suite ?? la reception du signal readyRead (reception des donn??es)


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
QChart *chartpersonnel = new QChart();

     chartpersonnel=p.statistique_chart();

    QChartView *chartviewpersonnel = new QChartView(chartpersonnel,ui->widget_3);

    chartviewpersonnel->resize(500,250);

    chartviewpersonnel->setRenderHint(QPainter::Antialiasing);

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
         QChart *chartpersonnel = new QChart();

              chartpersonnel=p.statistique_chart();

             QChartView *chartviewpersonnel = new QChartView(chartpersonnel,ui->widget_3);

             chartviewpersonnel->resize(500,250);

             chartviewpersonnel->setRenderHint(QPainter::Antialiasing);
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
    QChart *chartpersonnel = new QChart();

         chartpersonnel=p.statistique_chart();

        QChartView *chartviewpersonnel = new QChartView(chartpersonnel,ui->widget_3);

        chartviewpersonnel->resize(500,250);

        chartviewpersonnel->setRenderHint(QPainter::Antialiasing);
}
void Dialog::on_pushButton_2_clicked()
{
    QPdfWriter pdf("C:/Users/chedl/Desktop/base/smart_court_2A21/new_document.pdf");
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
              // painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/molka/OneDrive/Bureau/ligne-ic??ne-de-carte-d-identification-99265830.jpg"));
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
                painter.drawRect(0,3000,9600,i-3000);
               int reponse = QMessageBox::question(this, "G??nerer PDF", "<PDF Enregistr??>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {
                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/chedl/Desktop/base/smart_court_2A21/new_document.pdf"));
                       painter.end();
                   }
                   if (reponse == QMessageBox::No)
                   {
                        painter.end();
                   }
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

    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    QChart *chartaffaire = new QChart();

         chartaffaire=A.statAffaire();

        QChartView *chartviewaffaire = new QChartView(chartaffaire,ui->widget_2);

        chartviewaffaire->resize(400,250);

        chartviewaffaire->setRenderHint(QPainter::Antialiasing);
        chartviewaffaire->show();

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
    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    QChart *chartaffaire = new QChart();

         chartaffaire=A.statAffaire();

        QChartView *chartviewaffaire = new QChartView(chartaffaire,ui->widget_2);

        chartviewaffaire->resize(400,250);

        chartviewaffaire->setRenderHint(QPainter::Antialiasing);
         chartviewaffaire->show();
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
    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("modification non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    QChart *chartaffaire = new QChart();

         chartaffaire=A.statAffaire();

        QChartView *chartviewaffaire = new QChartView(chartaffaire,ui->widget_2);

        chartviewaffaire->resize(400,250);

        chartviewaffaire->setRenderHint(QPainter::Antialiasing);
         chartviewaffaire->show();
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
void Dialog::on_pdf_A_clicked()
{


    QString ach=".pdf";
        QPdfWriter pdf("C:/Users/chedl/OneDrive/Bureau/SmartCourt"+ach);


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
                              int reponse = QMessageBox::question(this, "G??nerer PDF", "<PDF Enregistr??>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/chedl /OneDrive/Bureau/SmartCourt"+ach));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }


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

        chartview->resize(300,250);

        chartview->setRenderHint(QPainter::Antialiasing);
         chartview->show();
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

}
    else{

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    QChart *chart = new QChart();

         chart=a.stat();

        QChartView *chartview = new QChartView(chart,ui->widget);

        chartview->resize(300,250);

        chartview->setRenderHint(QPainter::Antialiasing);
         chartview->show();

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
                    QString text = "Archiv?? avec success!";
                    QString titre = "Archivage complete!";

                }
}
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
               //Remplir tous les champs par les donn??es concern??es

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
                         QObject::tr("calendrier modifi??.\n"), QMessageBox::Cancel);
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
//////////////////////**ONS**/////////////////////////

void Dialog::on_pb_ajouter_clicked()
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
void Dialog::on_pb_modif_clicked()
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
                                QObject::tr("modification effectu??e.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void Dialog::on_pb_supprimer_clicked()
{
    int num_salle=ui->le_num_salle_supp->text().toInt();
    bool test=S.supprimer(num_salle);

    if (test)
    {
        ui->tab_salle->setModel(S.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("suppression effectu??e.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("suppression failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
void Dialog::on_pb_rechercher_clicked()
    {
        int num_salle=ui->le_rechercher->text().toInt();
        QString cin= QString::number(num_salle);
        if(num_salle!=0)
            ui->tab_salle->setModel(S.recherche(cin));
        else
            ui->tab_salle->setModel(S.afficher());
}
void Dialog::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="num de salle")
           ui->tab_salle->setModel(S.trier(3));
       else  if(arg1=="etage")
           ui->tab_salle->setModel(S.trier(2));
       else  if(arg1=="departement")
           ui->tab_salle->setModel(S.trier(1));
}
void Dialog::on_PDF_clicked()
{
    S.telechargerPDF();

                QMessageBox::information(nullptr,QObject::tr("OK"),
                           QObject::tr("T??l??chargement termin??"), QMessageBox::Cancel);

}
void Dialog::on_sm_clicked()
{
    sendMail();

}
void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void Dialog::sendMail()
{

    Smtp* smtp = new Smtp("ons.gharbi@esprit.tn", "211JFT8965", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("onsgharbi28@gmail.com", "onsgharbi28@gmail.com","test","hola");
}

/////chedhly

int test=0;
using namespace std;
void Dialog::on_afficher_activated(const QModelIndex &index)
{
    QString val=ui->afficher->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from SUSPET where id='"+val+" ' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_2->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->prenom->setText(qry.value(2).toString());
            ui->adresseaj->setText(qry.value(3).toString());
            ui->dateEdit->setDate(qry.value(4).toDate());
            ui->case_id->setText(qry.value(5).toString());
            ui->n1->setText(qry.value(6).toString());
            ui->n2->setText(qry.value(7).toString());
            ui->mail->setText(qry.value(8).toString());

            ui->nomp->setText(qry.value(1).toString());
            ui->prep->setText(qry.value(2).toString());

            ui->nome->setText(qry.value(1).toString());
            ui->pree->setText(qry.value(2).toString());

            ui->nb->setText(qry.value(1).toString());
            ui->pb->setText(qry.value(2).toString());
        }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctu??"),  QObject::tr("connection failed.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    // a coninuer

         QString text ="Suspect details :"+ ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),1)).toString()
                 +" "+ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),2)).toString()
                 +" "+ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),3)).toString()
                 +" "+ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),4)).toString()
                 +" "+ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),5)).toString()
                 +" "+ui->afficher->model()->data(ui->afficher->model()->index(ui->afficher->currentIndex().row(),6)).toString();
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
           ui->qr->setPixmap( QPixmap::fromImage(im.scaled(100,100,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
}
void Dialog::on_recherche_clicked()
{
    int id=ui->rech->text().toInt();
    QString cin= QString::number(id);
    if(id!=0)
        ui->afficher->setModel(s.recherche(cin));
    else
        ui->afficher->setModel(s.afficher());

}
void Dialog::mailSentt(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void Dialog::sendMaill()
{

    QString date,code,des;

    QString mail=ui->mail->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString case_id=ui->case_id->text();
    QString body="mr";
    QSqlQuery qry;
    qry.prepare("select * from AFFAIRES_JURIDIQUES where CODE='"+case_id+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            code=(qry.value(0).toString());
            date=(qry.value(3).toString());
            des=(qry.value(5).toString());
        }
    }
    QString t="salut monsieur/madame\n\n,\tmr"+ nom+prenom+"\n votre cas est le"+date+"\nla description de votre cas :"+des;
    Smtp* smtp = new Smtp("chedhly.ghorbel@esprit.tn", "211JMT9635", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail(mail, mail,+"\tcase  details",t);}
void Dialog::on_modifier_3_clicked()
{
    int n1=ui->n1->text().toInt();
    int n2=ui->n2->text().toInt();

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse = ui->adresseaj->text();
    QString case_id=ui->case_id->text();
    QString mail=ui->mail->text();

    //QDate date=ui->dateEdit->date();
    //QString d= QDate::toString(ui->dateEdit->date());
    int id=ui->id_2->text().toInt();

    QString cin= QString::number(id);
    QString num1= QString::number(n1);
    QString num2= QString::number(n2);



    QSqlQuery quer;
    quer.prepare("update SUSPET set id='"+cin+"', nom='"+nom+"',prenom='"+prenom+"',adresse='"+adresse+"',   case_id='"+case_id+"', numero1='"+num1+"', numero2='"+num2+"', mail='"+mail+"'where id='"+cin+"'");
    if(quer.exec())
    {
        ui->afficher->setModel(s.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("modification effectu?? \n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),  QObject::tr("modification non effectu?? \n"  "Click Cancel to exit."),QMessageBox::Cancel);

}
void Dialog::on_ajout_2_clicked()
{
    int id=ui->id_2->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse = ui->adresseaj->text();
    QString case_id=ui->case_id->text();
    QString mail=ui->mail->text();

    int n1=ui->n1->text().toInt();
    int n2=ui->n2->text().toInt();
    QDate date=ui->dateEdit_4->date();
    QString cin= QString::number(id);

    if(s.existance(cin))
    {
        int a=0,p=0;
        for(int i=0; i<mail.size(); i++)
        {
            if(mail[i]=='@')
                a++;
            else if(mail[i]=='.')
                p++;
        }



        if(a==1 && p>=1)
        {
            Suspet s( id,nom,prenom,adresse,date,case_id,n1,n2,mail);
            bool test=s.ajouter();
            if(test)
            {
                ui->afficher->setModel(s.afficher());

                QMessageBox::information(nullptr, QObject::tr("ajout effuctu??"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("mail n'est pas correcte"),   QObject::tr("check mail format.\n"  "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctu??"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

}
void Dialog::on_sm_2_clicked()
{
    sendMaill();
}
void Dialog::on_pushButton_3_clicked()
{
    int ched=0;
        //PRO BONO
        int tot=0;
        int k;
        int aaa=ui->id_2->text().toInt();
        int sal=0;
         sal=ui->salp->text().toInt();

        QString S= QString::number(sal);
        QString x= QString::number(aaa);

    int idd[10],as[10],numm[10],last[10],p[10],pp[10],nnn[10];


        QSqlQuery qry;
        int i=-1,chedli;
        qry.prepare("select * from PROBONO ");
        if(qry.exec())
        {
            while(qry.next())
            {

                int id=(qry.value(0).toInt());
                QString nom=(qry.value(1).toString());
                QString prenom=(qry.value(2).toString());
                int  salaire=(qry.value(3).toInt());
                int num=(qry.value(4).toInt());
                int l=(qry.value(5).toInt());
                 if(sal<=salaire)
                 {
                     i++;

                     idd[i]=id;
                    as[i]=(salaire);
                    numm[i]=(num);
                    last[i]=(l);
                    //i++;
               }
                 else if(sal>18000)
                     ched=1;
            }

            if(!ched)
            {
            for(int j=0; j<i; j++)
                tot+=numm[j];///numero de cases solved

            for(int j=0; j<i; j++)
              nnn[j]= numm[i]/tot;///pourcentage des cases solved par rapport tous

            int compteur=0;///to know hpw much the wining rate  of the last game
            for(int j=0; j<i; j++)
            {
                if(last[j])
                {
                    p[j]=(idd[j]);
                    pp[j]=(nnn[j]);
                    compteur++;
                }
                cout<<compteur<<"compt"<<endl;
            }
            if(!compteur)
            {
                int max=pp[0],posmax=0;
                for(int j=0; j<compteur; j++)
                {
                    if(max<pp[j])
                    {
                        max=pp[j];
                        posmax=j;
                    }
                }
                //id of the avocat is p[posmax]//ppfyh les  pourcentage
            k=p[posmax];

            }
            else//if all of them had losen cases
            {
                int max=numm[0],posmax=0;

                for(int j=0; j<i; j++)
                {
                    if(max<numm[j])
                    {
                        max=numm[j];
                        posmax=j;
                    }
                }
                k=idd[posmax];
                //id of the avocat is id[posmax]


            }

             chedli=1;
        }
        else
        {
            chedli=0;
        }}
        cout<<"id="<<k<<endl;
        if(!ched)
        {
            QString date,code,des;
            QString mail=ui->mail->text();
            QString nomaj=ui->nom->text();
            QString prenomaj=ui->prenom->text();
            QString case_idaj=ui->case_id->text();
            QString nom="HASSEN",prenom="JRIRA";

            QString body="mr";
            QSqlQuery qry1;
            QString iiii= QString::number(k);
            qry1.prepare("select * from PROBONO where idpb=?");
            qry1.addBindValue(iiii);
            if(qry1.exec())
            {
                while(qry1.next())
                {
            nom=(qry1.value(1).toString());
             prenom=(qry1.value(2).toString());
    }
            }

            QString t="salut monsieur/madame\n\n,\nmr"+ nomaj+prenomaj+"votre demande pour le probono a ete accept??\n"+"votre avocat est :"+nom+"\t"+prenom+"\n\n\ncordiallement.";
            Smtp* smtp = new Smtp("chedhly.ghorbel@esprit.tn", "211JMT9635", "smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail(mail, mail,+"DEMANDE PROBONO",t);
        }
        else
        {

            QString date,code,des;
            QString mail=ui->mail->text();
            QString nomaj=ui->nom->text();
            QString prenomaj=ui->prenom->text();
            QString case_idaj=ui->case_id->text();
            QString body="mr";
            QSqlQuery qry;


            if(qry.exec())
            {
                while(qry.next())
                {
                    code=(qry.value(0).toString());
                    date=(qry.value(3).toString());
                    des=(qry.value(5).toString());
                }
            }
            QString t="salut monsieur/madame\n\n,\nmr"+ nomaj+prenomaj+"votre demande pour le probono n'a pas  ete accept??\n";
            Smtp* smtp = new Smtp("chedhly.ghorbel@esprit.tn", "211JMT9635", "smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail(mail, mail,+"DEMANDE PROBONO",t);

        }
}
//check the lawyers disponibility about money
//check the propability of probono so that everyone can get a fair probono
//check the propability of success for each targeted lawyer
//check the last case if win or lose
//send mail so that they can know if they got accepted
void Dialog::on_comboBox_5_activated(const QString &arg1)
{
    if(arg1=="date d'ajout")
        ui->afficher->setModel(s.afficher());
    else  if(arg1=="id")
        ui->afficher->setModel(s.trier(3));
    else  if(arg1=="nom")
        ui->afficher->setModel(s.trier(2));
    else  if(arg1=="date de naissance")
        ui->afficher->setModel(s.trier(1));
}
void Dialog::on_supp_2_clicked()
{
    int id=ui->id_2->text().toInt();

    Suspet s1;
    bool test1;
    test1 =s1.supprimer(id);
    if(test1)
    {
        ui->afficher->setModel(s.afficher());

        QMessageBox::information(nullptr, QObject::tr("SUPP effuctu??"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supp n'est pas effuctu??"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}
void Dialog::on_comboBox_4_activated(const QString &arg1)
{
    if(arg1=="Bulletin numero 3")
    {
        ui->nb->show();
        ui->nomb->show();
        ui->pb->show();
        ui->prb->show();
        ui->bb->show();
        ui->ll->hide();
        ui->bpdf->show();
        ui->ls->hide();
        test=0;
    }
    else  if(arg1=="Liste des suspects")
    {
        test=1;
        ui->nb->hide();
        ui->nomb->hide();
        ui->pb->hide();
        ui->prb->hide();
        ui->ll->show();
        ui->bb->hide();
        ui->bpdf->hide();
        ui->ls->show();
    }
}

void Dialog::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->afficher);

    //colums to export
    obj.addField(0, "id", "char(20)");
    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "prenom", "char(20)");
    obj.addField(3, "adresse", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"), QString(tr("%1 records exported!")).arg(retVal)
                                );
    }
}

void Dialog::on_pdf_2_clicked()
{
    if(test)
    {
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QTextDocument doc;
        QPdfWriter pdf(fileName);
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::red);//titre
        painter.setFont(QFont("Cambria", 30));
        painter.drawText(1700,1200,"LISTES DES SUSPECTS");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Cambria",14));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Cambria",11));
        painter.drawText(200,3300,"CIN");
        painter.drawText(1300,3300,"PRENOM");
        painter.drawText(2700,3300,"NOM");
        painter.drawText(4000,3300,"ADRESSE");
        painter.drawText(5300,3300,"CASE ID");
        painter.drawText(6600,3300,"DATE");
        QSqlQuery query;
        query.prepare("select * from SUSPET");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2700,i,query.value(2).toString());
            painter.drawText(4000,i,query.value(3).toString());
            painter.drawText(5300,i,query.value(5).toString());
            painter.drawText(6600,i,query.value(4).toString());
            i = i + 500;
        }
       // doc.setHtml("Hello, World!\nLorem ipsum dolor sit amet, consectitur adipisci elit.");
        //  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }
    else

    {
        int id=ui->id_2->text().toInt();

        QString cin= QString::number(id);
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QTextDocument doc;
        QPdfWriter pdf(fileName);
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);//titre
        painter.setFont(QFont("Cambria", 30));
        painter.drawText(1700,1200,"BULLETEIN NUMERO 3");
        painter.setPen(Qt::red);
        painter.setFont(QFont("Cambria",14));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Cambria",11));
        painter.drawText(200,3300,"CIN");
        painter.drawText(1300,3300,"PRENOM");
        painter.drawText(2700,3300,"NOM");
        painter.drawText(4000,3300,"ADRESSE");
        painter.drawText(5300,3300,"CASE ID");
        painter.drawText(6600,3300,"DATE");
        QSqlQuery query;
        query.prepare("select * from SUSPET where id='"+cin+"' ");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2700,i,query.value(2).toString());
            painter.drawText(4000,i,query.value(3).toString());
            painter.drawText(5300,i,query.value(5).toString());
            painter.drawText(6600,i,query.value(4).toString());
            i = i + 500;
        }
        //  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }
}
