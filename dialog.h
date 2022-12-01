#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include<QPainter>
#include<QTextDocument>
#include <QPointF>
#include<QtGlobal>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "personnel.h"
#include"statistique.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_chercher_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_stat_clicked();

    void on_trier_clicked();

private:
    Ui::Dialog *ui;
    Personnel p;
     statistique *s;
};

#endif // DIALOG_H
