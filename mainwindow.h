#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"affaire_juridique.h"
#include"personnel.h"
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
    void on_login_clicked();

    void update();
    void update_2();
private:
    Ui::MainWindow *ui;
      Personnel P;
      Affaire_juridique A;
   arduino a,AA;
   QByteArray don;
     QByteArray ch;
};
#endif // MAINWINDOW_H
