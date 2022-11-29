#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"juge.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    void on_pB_juge_ajouter_2_clicked();

    void on_pB_juge_supprimer_2_clicked();

    void on_pB_juge_modifier_clicked();

private:
    Ui::MainWindow *ui;
    juge Ju;
};

#endif // MAINWINDOW_H
