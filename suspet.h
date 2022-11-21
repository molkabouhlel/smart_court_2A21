#ifndef SUSPET_H
#define SUSPET_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include <QDate>
#include <QAbstractItemModel>
#include <QPainter>
#include <QPrinter>
#include <QSslSocket>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>

#include "stmp.h"
class Suspet  {

    private:
    int id,numero1,numero2;
    QString nom,prenom,adresse,case_id,mail;
    QDate date_naissance;
public:
    Suspet();
    Suspet(int,QString,QString,QString,QDate,QString,int,int,QString);
    //Getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getID(){return id;}
    //Setters
    void setnom(QString n){ nom=n;}
    void setprenom(QString p){ prenom=p;}
    void setID(int id){this->id=id;}
    //Fonctions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * recherche(QString );
    void sendMail();
    QSqlQueryModel *trier(int );
    bool existance(QString );
    QString currDate();
    void pdf();



};

#endif // SUSPET_H
