#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Personnel
{
public:
    //const
    Personnel();
     Personnel( int,QString,QString,QString,QString,int,QString,float,QString );
     // getters
     QString getnom(){return nom ;}

     QString getprenom()
     {
         return prenom;
     }
     int getid(){return id;}
     QString getgrade()
     {
    return grade;
     }
    QString getlieu_t(){return lieu_t;}
    // setteurs
    void setnom(QString n ){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setid (int id){this->id=id;}
    void setgrade(QString nvg){grade=nvg;}
    void setlieu_t(QString lieu_t){this->lieu_t=lieu_t;}
    //cruds
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier();

private:
    int id;
  QString nom;
  QString prenom;
 QString date_n;
  QString lieu_t;
  int telephone;
  QString email;
  float salaire;
 QString grade;
};

#endif // PERSONNEL_H
