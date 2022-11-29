<<<<<<< HEAD
 #include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
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
=======
#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;

db.setDatabaseName("Source_Projet2A");
db.setUserName("MedAmine");//inserer nom de l'utilisateur
db.setPassword("amino159753");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


return  test;
}

void Connection::closeConnection(){db.close();}
>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6
