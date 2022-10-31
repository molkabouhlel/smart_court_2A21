#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include "salle.h"
#include <QMessageBox>
#include<QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui ->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pb_ajouter_clicked()
{
    int num_salle=ui->le_num_salle->text().toInt();
    QString departement=ui->le_departement->text();
    int etage=ui->le_etage->text().toInt();

     QString juge=ui->le_juge->text();
      QString suspect=ui->le_suspect->text();

       Salle S( num_salle,departement,etage,juge,suspect );
}
