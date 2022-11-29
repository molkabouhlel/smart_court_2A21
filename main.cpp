#include "mainwindow.h"
<<<<<<< HEAD
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
=======
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
<<<<<<< HEAD
    Suspet s;
    c.createconnect();
    MainWindow w;
    w.show();

=======
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
>>>>>>> b4d9196b4bc1a0aa1c6c96ca089072fe0f0d2aa6



    return a.exec();
}
