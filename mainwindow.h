#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "affaire_juridique.h"

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
    void on_ajouter_clicked();

    void on_done_clicked();

    void on_delete_2_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

private:
    Ui::MainWindow *ui;
    Affaire_juridique A;
};



#endif // MAINWINDOW_H
