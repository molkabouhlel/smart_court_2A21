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
    c.createconnect();
    MainWindow w;
    w.show();




    return a.exec();
}
