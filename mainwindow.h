#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 #include <QModelIndex>
#include <QMainWindow>
#include <QSslError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QMainWindow>
#include <QIntValidator>
#include <QApplication>
#include <QTextEdit>
#include <QFileDialog>
#include <QPrintDialog>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include<qrencode.h>
#include "suspet.h"
#include "stmp.h"
#include "tableprinter.h"
#include "exportexcel.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_supp_clicked();
    void on_ajout_clicked();
    void on_afficher_activated(const QModelIndex &index);
    void on_modifier_clicked();
    void on_recherche_clicked();
    void on_sm_clicked();
    void mailSent(QString);
    void sendMail();


    void on_comboBox_activated(const QString &arg1);


    void on_pushButton_2_clicked();

    void on_sms_clicked();

    void on_pushButton_3_clicked();

    void on_widget_customContextMenuRequested(const QPoint &pos);


    void on_pdf_clicked();

    void on_comboBox_2_activated(const QString &arg1);
    void update();



private:
    Ui::MainWindow *ui;
    Suspet s;
    QPrinter printer;
    QPainter painter;
    QByteArray don;
    QByteArray ch;

    arduino A;

};
#endif // MAINWINDOW_H
