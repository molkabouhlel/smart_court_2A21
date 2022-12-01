#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"calendrier.h"
#include <QMainWindow>
#include <QtCharts>
#include<QCalendarWidget>
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
    void on_ajout_clicked();

    void on_supp_clicked();

    void on_modifier_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_trie_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_calendarWidgett_clicked(const QDate &date);

    void on_pushButton_clicked();



    void on_tabWidget_currentChanged(int index);


private:
    Ui::MainWindow *ui;
    Calendrier a;
};
#endif // MAINWINDOW_H
