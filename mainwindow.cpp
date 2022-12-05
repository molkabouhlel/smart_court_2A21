#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include<QMessageBox>
#include"arduino.h"
#include"arduino1.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ARDUINO chedli molka
    int ret=a.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données)
         //chedli is writing the fututre

         //arduino amine ons
         int retTT=AA.connect_arduino(); // lancer la connexion à arduino
             switch(retTT){
             case(0):qDebug()<< "arduino is available and connected to : "<< AA.getarduino_port_name();
                 break;
             case(1):qDebug() << "arduino is available but not connected to :" <<AA.getarduino_port_name();
                break;
             case(-1):qDebug() << "arduino is not available";
             }
              QObject::connect(AA.getserial(),SIGNAL(readyRead()),this,SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    arduino a;
    Personnel p;
    QString nom,mot_de_passe,grade;
       nom=ui->nom_log->text();
     mot_de_passe=ui->mp_log->text();
     grade=ui->l_grade_lg->text();
       QSqlQuery qry;

   int i=1;
          /* while(qry.next())
           {

               i++;
           }*/
           if(i==1)
           {
               QMessageBox::information(nullptr,QObject::tr("login done"),
                                        QObject::tr("login succesfully \n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);


               Dialog d;
             d.setModal(true);
               d.exec();
               }


             else if(i<1)
                {
                     QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                             QObject::tr("FAILD TO connected ..........  \n"
                                                          "erreur erreur inaccesible \n"
                                                         "vous n etez pas en registrer dans notre base de donner"
                                                         "Click Cancel to exit."),QMessageBox::Cancel);


}
}

QString ch1="";
void MainWindow::update()
{
Personnel p;
    don=a.read_from_arduino();
    QByteArray d="";
    qDebug() <<"ddddd"<<ch<<*don;

    if(*don=='1')
        ch=ch+'1';
    else if(*don=='2')
        ch=ch+'2';
    else if(*don=='3')
        ch=ch+'3';
    else if(*don=='4')
        ch=ch+'4';
    else if(*don=='5')
        ch=ch+'5';
    else if(*don=='6')
        ch=ch+'6';
    else if(*don=='7')
        ch=ch+'7';
    else if(*don=='8')
        ch=ch+'8';
    else if(*don=='9')
        ch=ch+'9';
    else if(*don=='0')
        ch=ch+'0';


    QByteArray am="WRONG";

    if(*don=='*')
    {

        QSqlQuery query;
        QString test=QString(ch);

    if(!p.existance(test))
    {
        qDebug() <<"testing"<<test;
        QString nom,prenom;
        query.prepare("select * from personnels where id='"+test+"' ");
        if(query.exec())
        {
            while(query.next())
            {
                 nom=(query.value(1).toString());
                 prenom=(query.value(2).toString());
            }
        query.exec();
        QString tt=nom+" "+prenom;
        QByteArray z=tt.toUtf8();
        a.write_to_arduino(z);
    }}
    else
        {
    a.write_to_arduino("WRONG\n");
        }
        ch="";

}



    Arduino AA;
    QSqlQuery query;
     QByteArray data="";
   //QByteArray nom ,pwd,grade;
     QString nom="" ,pwd="",grade="";

    data=AA.read_from_arduino();
     qDebug() <<  " data is " <<data;
     ch1=ch1+data;
     qDebug() <<  " ch1 is " <<ch1;


    if(ch1!="" && ch1.length()>=12)
       {

         query.prepare("SELECT* FROM Personnels WHERE mot_de_passe='"+ch1+"'  ");
         qDebug() << query.exec();
         while (query.next())
         {
         nom =query.value(1).toString();
         pwd=query.value(8).toString();
         grade=query.value(9).toString();
         }
         qDebug() << nom;
         qDebug() << pwd;
         qDebug() << grade;
         ui->nom_log->setText(nom);
         ui->mp_log->setText(pwd);
         ui->l_grade_lg->setText(grade);
         if(pwd!="")
         {
         QString message ="Bienvenue "+ nom;
         QByteArray br = message.toUtf8();
         AA.write_to_arduino(br);}



        else
        {
           QString message="";
             message ="donne introuvable";
            QByteArray br = message.toUtf8();
            AA.write_to_arduino(br);
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("FAILED TO connected ..........  \n"
                                                 "acces denied \n"

                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }


}
    if(ch1.length()>=12)
     {
     ch1="";
     }
}



//QString ch1="";

void MainWindow::update_2()
{
    Arduino AA;
    Affaire_juridique A;
    QSqlQuery query;
     QByteArray data="";
   //QByteArray nom ,pwd,grade;
     QString nom="" ,pwd="",grade="";

    data=AA.read_from_arduino();
     qDebug() <<  " data is " <<data;
     ch1=ch1+data;
     qDebug() <<  " ch1 is " <<ch1;


    if(ch1!="" && ch1.length()>=12)
       {

         query.prepare("SELECT* FROM Personnels WHERE mot_de_passe='"+ch1+"'  ");
         qDebug() << query.exec();
         while (query.next())
         {
         nom =query.value(1).toString();
         pwd=query.value(8).toString();
         grade=query.value(9).toString();
         }
         qDebug() << nom;
         qDebug() << pwd;
         qDebug() << grade;
         ui->nom_log->setText(nom);
         ui->mp_log->setText(pwd);
         ui->l_grade_lg->setText(grade);
         if(pwd!="")
         {
         QString message ="Bienvenue "+ nom;
         QByteArray br = message.toUtf8();
         AA.write_to_arduino(br);}



        else
        {
           QString message="";
             message ="donne introuvable";
            QByteArray br = message.toUtf8();
            AA.write_to_arduino(br);
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("FAILED TO connected ..........  \n"
                                                 "acces denied \n"

                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }


}
    if(ch1.length()>=12)
     {
     ch1="";
     }
}


void MainWindow::on_arduino_clicked()
{

}
