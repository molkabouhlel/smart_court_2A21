#ifndef SUSPET_H
#define SUSPET_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include <QDate>

class Suspet
{
    private:
    int id,numero1,numero2;
    QString nom,prenom,adresse,case_id;
    QDate date_naissance;
public:
    Suspet();
    Suspet(int,QString,QString,QString,QDate,QString,int,int);
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


};

#endif // SUSPET_H
