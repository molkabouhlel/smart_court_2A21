#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include<QSqlQueryModel>

class Salle
{
public:
    Salle();
    Salle(int,QString,int,QString,QString);
    int getnum_salle();
    int getetage();
    QString getdepartement();
    QString getjuge();
    QString getsuspect();
    void setnum_salle(int);
    void setetage(int);
    void setdepartement(QString);
    void setjuge(QString);
    void setsuspect(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();




private:
    int num_salle,etage;
    QString departement,juge,suspect;
};

#endif // SALLE_H


