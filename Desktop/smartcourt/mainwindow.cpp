#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include<QPrintDialog>
#include <QMessageBox>
#include <QFileDialog>
#include<QDebug>
#include <QDateTime>
#include <QDate>
#include"excel.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nbr_pr->setValidator(new QIntValidator(100,500, this));
    ui->tableView->setModel(a.afficher());
    QTextCharFormat format = ui->calendarWidgett->weekdayTextFormat(Qt::Saturday);
       format.setForeground(QBrush(Qt::black, Qt::SolidPattern));
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Saturday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Sunday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Monday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Tuesday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Wednesday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Thursday, format);
       ui->calendarWidgett->setWeekdayTextFormat(Qt::Friday, format);
       QDateTime cdt = QDateTime::currentDateTime();
          ui->dateEdit->setDateTime(cdt);
ui->dateEdit_2->setDateTime(cdt);
//stat
       QChart *chart = new QChart();

            chart=a.stat();

           QChartView *chartview = new QChartView(chart,ui->widget);

           chartview->resize(400,300);

           chartview->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajout_clicked()
{
    QString id_r=ui->id->text();
    QString type_r=ui->comboBox_2->currentText();
    QString date_d=ui->dateEdit->text();
    QString date_f=ui->dateEdit_2->text();
    QString local=ui->local->text();
    int nb_per=ui->nbr_pr->text().toInt();
    Calendrier c(id_r,date_d,date_f,local, nb_per,type_r);
    bool test =c.ajouter();
    if(test)
    {
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->id->setText("");

        ui->local->setText("");
        ui->nbr_pr->setText("");
         QDateTime cdt = QDateTime::currentDateTime();
        ui->dateEdit->setDateTime(cdt);
ui->dateEdit_2->setDateTime(cdt);


}
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    QChart *chart = new QChart();

         chart=a.stat();

        QChartView *chartview = new QChartView(chart,ui->widget);

        chartview->resize(400,300);

        chartview->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::on_supp_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
      QString id_r = index.data(Qt::DisplayRole).toString();
      QTextCharFormat formattt ;
      QDate datet;
          formattt.setForeground(QBrush(Qt::black, Qt::SolidPattern));


    bool test =a.supprimer(id_r);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView->setModel(a.afficher());
 ui->calendarWidgett->setDateTextFormat(datet, formattt);
 QChart *chart = new QChart();

      chart=a.stat();

     QChartView *chartview = new QChartView(chart,ui->widget);

     chartview->resize(400,300);

     chartview->setRenderHint(QPainter::Antialiasing);
}
    else{

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_modifier_clicked()
{

    QString id=ui->id->text();
    QString type_r=ui->comboBox_2->currentText();
    QString date_d=ui->dateEdit->text();
    QString date_f=ui->dateEdit_2->text();
    QString local=ui->local->text();
    int nb_per=ui->nbr_pr->text().toInt();




    Calendrier d (id,date_d,date_f,local, nb_per,type_r);
    if(d.modifiers(id))
    {
             QMessageBox::information(nullptr, QObject::tr("Modifier un calendrier"),
                         QObject::tr("calendrier modifié.\n"), QMessageBox::Cancel);
             ui->tableView->setModel(a.afficher());

              QChart *chart = new QChart();

                   chart=a.stat();

                  QChartView *chartview = new QChartView(chart,ui->widget);

                  chartview->resize(400,300);

                  chartview->setRenderHint(QPainter::Antialiasing);
                  ui->id->setText("");

                  ui->local->setText("");
                  ui->nbr_pr->setText("");
                  QDateTime cdt = QDateTime::currentDateTime();
                 ui->dateEdit->setDateTime(cdt);
         ui->dateEdit_2->setDateTime(cdt);




    }
    else
    {
       QMessageBox::critical(nullptr, QObject::tr("Modifier un calendrier"),

                             QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);

    }
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->tableView->setModel(a.rechercher(arg1));

}

void MainWindow::on_trie_clicked()
{QString trie=ui->comboBox->currentText();
    if(trie=="DATE"){
         ui->tableView->setModel(a.AfficherTri());}
       else if(trie=="ID"){
          ui->tableView->setModel(a.AfficherTriid());
       }
       else if(trie=="TYPE"){
          ui->tableView->setModel(a.AfficherTritype());
       }
}




//pdf

void MainWindow::on_pushButton_5_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView->model()->rowCount();
                            const int columnCount = ui->tableView->model()->columnCount();

                            out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("strTitle")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"

                               //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H1> SmartCourt \n \n\n\n</H1><H2>Liste des rendez_vous \n \n\n\n</H2><H3> \n \n\n\n</H3></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


                            // headers
                            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView->isColumnHidden(column)) {
                                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table> </center>\n"
                                "</body>\n"
                                "</html>\n";

                      QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}
//export excel
void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                tr("Excel Files (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "rendez_vous", ui->tableView);

                //colums to export
                obj.addField(0, "ID_R", "char(20)");
                obj.addField(1, "DATE_D", "char(20)");
                obj.addField(2, "DATE_F", "char(20)");
                obj.addField(3, "TYPE_R", "char(20)");
                obj.addField(4, "NB_PER", "NUMBER");
                obj.addField(5, "LOCAL", "char(20)");





                int retVal = obj.export2Excel();
                if( retVal > 0)
                {
                    QString text = "Archivé avec success!";
                    QString titre = "Archivage complete!";

                }
}









//charger
void MainWindow::on_pushButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
                QString id_r = index.data(Qt::DisplayRole).toString();
                QString nbr = ui->tableView->model()->index(index.row(), 4).data(Qt::DisplayRole).toString();
                ui->nbr_pr->setText(nbr);
                QString type = ui->tableView->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
                ui->comboBox_2->setCurrentText(type);

                //QString date = ui->tableView->model()->index(index.row(), 1).data(Qt::DisplayRole).toDateTime();
                ui->dateEdit_2->setDate(ui->tableView->model()->index(index.row(), 2).data(Qt::DisplayRole).toDate());
                  ui->dateEdit->setDate(ui->tableView->model()->index(index.row(), 1).data(Qt::DisplayRole).toDate());

                QString id = ui->tableView->model()->index(index.row(), 0).data(Qt::DisplayRole).toString();
                ui->id->setText(id);
                QString local = ui->tableView->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
                ui->local->setText(local);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QDate datet;
       QSqlQuery qry;
       QTextCharFormat formattt ;
       formattt.setForeground(QBrush(Qt::white, Qt::SolidPattern));

       qry.prepare("select DATE_D from CALENDRIER");
       if(qry.exec())
       {
           while(qry.next())
           {
               datet=qry.value(1).toDate();
               ui->calendarWidgett->setDateTextFormat(datet, formattt);


           }
       }
}
//caledrier
void MainWindow::on_calendarWidgett_clicked(const QDate &date)
{
    ui->dateEdit_3->setDate(date);
    QString aa=ui->dateEdit_3->text();


       QSqlQuery qry;


       qry.prepare("select * from CALENDRIER ");

       if(qry.exec())
       {
           while(qry.next())
           {
               //Remplir tous les champs par les données concernées

   if(qry.value(1).toString()==aa)
   {
               ui->lineEdit->setText(qry.value(1).toString());
               ui->lineEdit_3->setText(qry.value(3).toString());
               ui->lineEdit_2->setText(qry.value(5).toString());
               ui->lineEdit_7->setText(qry.value(2).toString());
               ui->lineEdit_4->setText(qry.value(4).toString());

       ui->lineEdit_6->setText(qry.value(0).toString());


   }

   }//fin while
   }//fin if qry
}
