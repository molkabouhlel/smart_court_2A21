#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Salle
{
public:
    //const
    Salle();
         Salle( int,QString,int,QString,QString );
         // getters
         int getnum_salle(){return num_salle ;}

         QString getdepartement()
         {
             return departement;
         }
         int getetage(){return etage;}
         QString getjuge()
         {
        return juge;
         }
        QString getsuspect(){return suspect;}
        // setteurs

    void setnum_salle(int n);
    void setdepartement(QString n);
    void setetage(int n);
    void setjuge(QString n);
    void setsuspect(QString n);

    bool ajouter();

private:
    int num_salle;
    QString departement;
    int etage;
    QString juge;
    QString suspect;

};

#endif // SALLE_H
