#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "twilio.h"
#include <winsock2.h>
#include <windows.h>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include"qrcodegen.hpp"
//#include <openssl/ssl.h>
int test;
using namespace std;
=======
#include "affaire_juridique.h"
#include <QMessageBox>
#include <QIntValidator>

>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->ll->hide();
    ui->ls->hide();

    ui->id->setValidator (new QIntValidator(0, 99999999, this));
    ui->n1->setValidator (new QIntValidator(0, 99999999, this));
    ui->n2->setValidator (new QIntValidator(0, 99999999, this));
    QRegularExpression rx("^[A-Za-z]+$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->nom->setValidator(validator);
    ui->prenom->setValidator(validator);
    ui->adresseaj->setValidator(validator);
    QRegularExpression regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
    QValidator *val = new QRegularExpressionValidator(regex, this);
    ui->mail->setValidator(val);
    ui->afficher->setModel(s.afficher());
    ui->comboBox->addItem("date d'ajout") ;
    ui->comboBox->addItem("id") ;
    ui->comboBox->addItem("date de naissance");
    ui->comboBox->addItem("nom");
}
=======
    ui->Code->setValidator( new QIntValidator(0, 99999999, this));
    ui->Nom->setMaxLength(10);
    ui->cause->setMaxLength(10);


    ui->Affichage->setModel(A.afficher());
    /*for(int i=0;i<2;i++)
    ui->Affichage->setIndexWidget(ui->Affichage->model()->index(i, 7),ui->groupBox);*/
}

>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6
MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD
void MainWindow::on_supp_clicked()
{
    int id=ui->id->text().toInt();

    Suspet s1;
    bool test1;
    test1 =s1.supprimer(id);
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
    QString mail=ui->mail->text();

    int n1=ui->n1->text().toInt();
    int n2=ui->n2->text().toInt();
    QDate date=ui->dateEdit->date();
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

                QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("mail n'est pas correcte"),   QObject::tr("check mail format.\n"  "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_afficher_activated(const QModelIndex &index)
{
    QString val=ui->afficher->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from SUSPET where id='"+val+" ' ");
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
            ui->n2->setText(qry.value(7).toString());
            ui->mail->setText(qry.value(8).toString());

            ui->nomp->setText(qry.value(1).toString());
            ui->prep->setText(qry.value(2).toString());

            ui->nome->setText(qry.value(1).toString());
            ui->pree->setText(qry.value(2).toString());

        }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctué"),  QObject::tr("connection failed.\n" "Click Cancel to exit."), QMessageBox::Cancel);
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
void MainWindow::on_modifier_clicked()
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
    int id=ui->id->text().toInt();

    QString cin= QString::number(id);
    QString num1= QString::number(n1);
    QString num2= QString::number(n2);



    QSqlQuery quer;
    quer.prepare("update SUSPET set id='"+cin+"', nom='"+nom+"',prenom='"+prenom+"',adresse='"+adresse+"',   case_id='"+case_id+"', numero1='"+num1+"', numero2='"+num2+"', mail='"+mail+"'where id='"+cin+"'");
    if(quer.exec())
    {
        ui->afficher->setModel(s.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("modification effectué \n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),  QObject::tr("modification non effectué \n"  "Click Cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::on_recherche_clicked()
{
    int id=ui->rech->text().toInt();
    QString cin= QString::number(id);
    if(id!=0)
        ui->afficher->setModel(s.recherche(cin));
    else
        ui->afficher->setModel(s.afficher());

}

void MainWindow::on_sm_clicked()
{
    sendMail();

}
void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::sendMail()
{

    QString date,code,des;

    QString mail=ui->mail->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString case_id=ui->case_id->text();
    QString body="mr";
    QSqlQuery qry;
    qry.prepare("select * from AFFAIRES_JURIQIUES where CODE_A='"+case_id+"'");
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
    smtp->sendMail(mail, mail,+"\tcase  details",t);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
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
void MainWindow::on_pushButton_2_clicked()
{
int ched=0;
    //PRO BONO
    int tot=0;
    int k;
    int aaa=ui->id->text().toInt();
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

        QString t="salut monsieur/madame\n\n,\nmr"+ nomaj+prenomaj+"votre demande pour le probono a ete accepté\n"+"votre avocat est :"+nom+"\t"+prenom+"\n\n\ncordiallement.";
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
        QString t="salut monsieur/madame\n\n,\nmr"+ nomaj+prenomaj+"votre demande pour le probono n'a pas  ete accepté\n";
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






void MainWindow::on_sms_clicked()
{

    /* try number 8:
        std::string account_sid;
        std::string auth_token;
        std::string message;
        std::string from_number;
        std::string to_number;
        std::string picture_url;
        bool verbose = false;

        opterr = 0;


        if ( account_sid.empty() or auth_token.empty() or from_number.empty()
                or to_number.empty() or message.empty() ) {
                std::cout<< "You didn't include all necessary inputs!\n"
                        "Call using -h for help.\n" << std::endl;
        }

        // Instantiate a twilio object and call send_message
        std::string response;
        auto twilio = std::make_shared<twilio::Twilio>( account_sid,  auth_token);

        bool message_success = twilio->send_message(to_number,
                from_number,
                message,
                response,
                picture_url,
                verbose
        );

        // Report success or failure
        if (!message_success) {
                if (verbose) {
                        std::cout << "Message send failed." << std::endl;
                        if (!response.empty()) {
                                std::cout << "Response:" << std::endl
                                        << response << std::endl;
                        }
                }
        } else if (verbose) {
                std::cout << "SMS sent successfully!" << std::endl;
                std::cout << "Response:" << std::endl << response
                        << std::endl;
        }
    */

}

void MainWindow::on_pushButton_3_clicked()
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

void MainWindow::on_widget_customContextMenuRequested(const QPoint &pos)
{
    /*
       QPainter painter(ui->widget);
       //NOTE: I have hardcoded some parameters here that would make more sense as variables.
       QRcode *qr = QRcode_encodeString("hello", 1, QR_ECLEVEL_L, QR_MODE_8, 1);
       if(0!=qr)
       {
           QColor fg("black");
           QColor bg("white");
           painter.setBrush(bg);
           painter.setPen(Qt::NoPen);
           painter.drawRect(0,0,width(),height());
           painter.setBrush(fg);
           const int s=qr->width>0?qr->width:1;
           const double w=width();
           const double h=height();
           const double aspect=w/h;
           const double scale=((aspect>1.0)?h:w)/s;
           for(int y=0; y<s; y++)
           {
               const int yy=y*s;
               for(int x=0; x<s; x++)
               {
                   const int xx=yy+x;
                   const unsigned char b=qr->data[xx];
                   if(b &0x01)
                   {
                       const double rx1=x*scale, ry1=y*scale;
                       QRectF r(rx1, ry1, scale, scale);
                       painter.drawRects(&r,1);
                   }
               }
           }
          // QRcode_free(qr);
       }
       else
       {
           QColor error("red");
           painter.setBrush(error);
           painter.drawRect(0,0,width(),height());
           qDebug()<<"QR FAIL: "<< strerror(errno);
       }
       qr=0;*/
}

void MainWindow::on_pdf_clicked()
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
        doc.setHtml("Hello, World!\nLorem ipsum dolor sit amet, consectitur adipisci elit.");
        //  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }
    else

    {
        int id=ui->id->text().toInt();

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
void MainWindow::on_comboBox_2_activated(const QString &arg1)
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

=======

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
>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6
