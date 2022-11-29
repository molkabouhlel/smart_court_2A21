    #ifndef MAINWINDOW_H
#define MAINWINDOW_H
 #include <QModelIndex>
#include <QMainWindow>
#include"suspet.h"

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

    void on_supp_clicked();
    void on_ajout_clicked();

    void on_afficher_activated(const QModelIndex &index);

    void on_modifier_clicked();



    void on_recherche_clicked();

private:
    Ui::MainWindow *ui;
    Suspet s;
};
#endif // MAINWINDOW_H
