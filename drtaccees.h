#ifndef DRTACCEES_H
#define DRTACCEES_H

#include <QDialog>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "personnel.h"
namespace Ui {
class drtaccees;
}

class drtaccees : public QDialog
{
    Q_OBJECT

public:
    explicit drtaccees(QWidget *parent = nullptr);
    ~drtaccees();
 void afficher();
 void ajouter();
private slots:
 void on_ok_dr_clicked();

 void on_modifier_clicked();

private:
    Ui::drtaccees *ui;
        Personnel p;
};

#endif // DRTACCEES_H
