
#include "connection.h"
//test git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("MedAmine");//inserer nom de l'utilisateur
db.setPassword("amino159753");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;





    return  test;
}

