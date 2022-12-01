#ifndef GEST_ARDUINO_H
#define GEST_ARDUINO_H
#include "arduino.h"
#include <QDialog>
#include "billet.h"
#include "vol.h"
namespace Ui {
class gest_arduino;
}

class gest_arduino : public QDialog
{
    Q_OBJECT

public:
    explicit gest_arduino(QWidget *parent = nullptr);
    ~gest_arduino();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gest_arduino *ui;
     arduino a;
     Billet bi;
};

#endif // GEST_ARDUINO_H
