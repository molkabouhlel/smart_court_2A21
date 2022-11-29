#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
<<<<<<< HEAD
#include <QtQrCode>

class Connection
{
public:
    Connection();
    bool createconnect();
};

=======


class Connection
{
        QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeConnection();
};


>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6
#endif // CONNECTION_H
