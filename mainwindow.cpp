#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator( new QIntValidator(0, 99999999, this));
        ui->comboBox->addItem("");
         ui->comboBox_2->addItem("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int ref_rec=ui->lineEdit->text().toInt();

     QString type_panne=ui->comboBox_3->currentText();
     QString description=ui->lineEdit_11->text();
    reclamation R(ref_rec,type_panne,description);
     bool test=R.ajouter();
    QMessageBox msgbox;
    if(ref_rec!=0 && type_panne.size()>0 && description.size()>0 )
    {
    if(test)
    {msgbox.setText("Ajout avec succes.");
    ui->comboBox->addItem(ui->lineEdit->text());
    ui->comboBox_2->addItem(ui->lineEdit->text());
        ui->tableView->setModel(R.afficher());
          ui->lineEdit->setText("");

        ui->comboBox_3->setCurrentText("");
         ui->lineEdit_11->setText("");

    }
    else
        msgbox.setText("Echec d'ajout");
    msgbox.exec();
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                             QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_pushButton_2_clicked()
{
    int ref_rec=ui->comboBox->currentIndex();

        QString type_panne=ui->comboBox_4->currentText();
        QString description=ui->lineEdit_12->text();
        reclamation R(ref_rec,type_panne,description);



        R.setref_rec(ui->comboBox->currentIndex()) ;
        bool test=R.modifier(R.getref_rec()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            ui->tableView->setModel(R.afficher());

        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
   reclamation R; R.setref_rec(ui->comboBox_2->currentText().toInt());
    bool test=R.supprimer(R.getref_rec());
    QMessageBox msgbox;
    msgbox.setText("voulez-vous le supprimer ?");
        msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            ui->tableView->setModel(R.afficher());
            ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
                        ui->comboBox->removeItem(ui->comboBox_2->currentIndex());
            msgbox.setText("Suppression avec succes...");
            msgbox.setStandardButtons(QMessageBox::Ok);
            msgbox.exec();
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
            // should never be reached
            break;
      }
}


void MainWindow::on_comboBox_activated(const QString &arg1)

    {
    QSqlQuery query;
        int ref_rec=ui->comboBox->currentIndex() ;
       query.prepare("Select * from maintenance where ref_rec=:ref_rec" );
               query.bindValue(0,ref_rec) ;
               query.exec();
        query.next() ;


        ui->comboBox_4->setCurrentText(query.value("type_panne").toString());
        ui->lineEdit_12->setText(query.value("description").toString());


}

void MainWindow::afficherBD()
{
reclamation afe;
ui->tableView->setModel(afe.afficher());
QSqlQuery qry;
qry.prepare("select ref_rec from maintenance");
qry.exec();
while(qry.next())
{
    ui->comboBox->addItem(qry.value("ref_rec").toString());
    ui->comboBox_2->addItem(qry.value("ref_rec").toString());
}

}

void MainWindow::on_pushButton_7_clicked()
{
    reclamation R;
        QString crit=ui->comboBox_5->currentText();
        if(crit=="ref_rec")
        {
            ui->tableView->setModel(R.tri_ref_rec());
        }
        else if(crit=="type_panne")
        {
            ui->tableView->setModel(R.tri_type_panne());
        }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(R.rechercher(arg1));
}

void MainWindow::on_pushButton_6_clicked()
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
                                           "<center> <H1>Liste des reclamations</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                       // headers
                                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                       out<<"<cellspacing=10 cellpadding=3>";
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
