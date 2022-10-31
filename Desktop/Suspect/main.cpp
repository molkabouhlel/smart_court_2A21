#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    Suspet s;
    MainWindow w;
    w.show();
    bool test=c.createconnect();

    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
