#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include<QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrinterInfo>
#include<QtPrintSupport/QPrintDialog>

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

bool existance(QString num_salle);
QSqlQueryModel *recherche(QString num_salle);
QSqlQueryModel * trier(int test);
void pdf();



private:
    int num_salle,etage;
    QString departement,juge,suspect;
};

#endif // SALLE_H


