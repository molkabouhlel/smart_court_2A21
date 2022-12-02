#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
<<<<<<< HEAD
{bool test=false;

db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A.");
db.setUserName("sarra");//inserer nom de l'utilisateur
db.setPassword("sarra");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}


=======
{
   bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("chedli");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;
   return  test;
}
>>>>>>> ebf44bdb5d15d027bc0687731f6d93865e058fb0
