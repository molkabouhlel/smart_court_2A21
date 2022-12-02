#include "localisation.h"
#include "ui_localisation.h"

localisation::localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::localisation)
{
    ui->setupUi(this);
}

localisation::~localisation()
{
    delete ui;
}

void localisation::map()
{
QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                   QCoreApplication::organizationName(), QCoreApplication::applicationName());

ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/First+Instance+of+Ariana/@36.8523887,10.1917259,17z/data=!3m1!4b1!4m5!3m4!1s0x12fd34c9e6d65dd3:0x8a2022ee3c0f8bde!8m2!3d36.8524143!4d10.1940003");
}
