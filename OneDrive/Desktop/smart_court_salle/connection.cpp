#include "connection.h"
//Test tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Ons");//inserer nom de l'utilisateur
db.setPassword("Ons");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeconnect(){db.close();}
