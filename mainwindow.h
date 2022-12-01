#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"statistique.h"
#include"personnel.h"
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

    void on_arduino_clicked();
    void update();


private:
    Ui::MainWindow *ui;
      Personnel P;
   statistique *s;
   arduino a;
   QByteArray don;
     QByteArray ch;
};
#endif // MAINWINDOW_H
