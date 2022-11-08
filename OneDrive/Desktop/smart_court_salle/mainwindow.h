#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "salle.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modif_clicked();

    void on_pb_supprimer_clicked();



    void on_pb_rechercher_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_le_departement_activated(const QString &arg1);

    void on_le_etage_activated(const QString &arg1);


    void on_PDF_clicked();

private:
    Ui::MainWindow *ui;
    Salle S;
};

#endif // MAINWINDOW_H
