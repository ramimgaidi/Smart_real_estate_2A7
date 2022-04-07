#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include "qrcode.h"
#include "qrwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->matricule_2->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->tableView->setModel(E.afficher());
    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
    int matricule=ui->matricule_2->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int cin=ui->cin->text().toInt();
    QString adresse=ui->adresse->text();
    QString email=ui->email->text();
    int tel=ui->tel->text().toInt();
    QString date_embauche=ui->date_embauche->text();
    int heure=ui->heure->text().toInt();
    int prix_heure=ui->prix_heure->text().toInt();

    employe E(matricule,nom,prenom,cin,adresse,email,tel,date_embauche,heure,prix_heure);
        bool test=E.ajouter();
        QMessageBox msgbox;
        if(matricule!=0 && nom.size()>0 && prenom.size()>0 && cin!=0 && adresse.size()>0 && email.size()>0 && tel!=0 && date_embauche.size()>0 && heure!=0 && prix_heure!=0)
        {
        if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->tableView->setModel(E.afficher());
            ui->nom->setText("");
            ui->prenom->setText("");
            ui->cin->setText("");
            ui->adresse->setText("");
            ui->email->setText("");
            ui->tel->setText("");
            ui->date_embauche->setText("");
            ui->heure->setText("");
            ui->prix_heure->setText("");


        }
        else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
        }
        else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                 QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    */


/*void MainWindow::on_pushButton_2_clicked()
{
    int ref_log=ui->lineEdit_4->text().toInt();
    QString type_log=ui->comboBox->currentText();
     QString adresse_log=ui->lineEdit_6->text();
        int surface_log=ui->lineEdit_19->text().toInt();
         int piece_log=ui->lineEdit_20->text().toInt();
          int dispo_log=ui->lineEdit_21->text().toInt();
        Logement L(ref_log,type_log,adresse_log,surface_log,piece_log,dispo_log);


        L.setref_log(ui->lineEdit_4->text().toInt()) ;
        bool test=L.modifier(L.getref_log()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            ui->tableView->setModel(L.afficher());
        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Logement L1; L1.setref_log(ui->lineEdit_7->text().toInt());
    bool test=L1.supprimer(L1.getref_log());
    QMessageBox msgbox;
    if(test)
    {msgbox.setText("Suppression avec succes.");
        ui->tableView->setModel(L.afficher());
    }
    else
        msgbox.setText("Echec de suppression");
    msgbox.exec();
}
*/

void MainWindow::on_ajouter_employe_clicked()
{
    int matricule=ui->matricule_2->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int cin=ui->cin->text().toInt();
    QString adresse=ui->adresse->text();
    QString email=ui->email->text();
    int tel=ui->tel->text().toInt();
    QString date_embauche=ui->date_embauche->text();
    int heure=ui->heure->text().toInt();
    int prix_heure=ui->prix_heure->text().toInt();

    employe E(matricule,nom,prenom,cin,adresse,email,tel,date_embauche,heure,prix_heure);
        bool test=E.ajouter();
        QMessageBox msgbox;
        if(matricule!=0 && nom.size()>0 && prenom.size()>0 && cin!=0 && adresse.size()>0 && email.size()>0 && tel!=0 && date_embauche.size()>0 && heure!=0 && prix_heure!=0)
        {
        if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->comboBox->addItem(ui->matricule_2->text());
                    ui->comboBox_2->addItem(ui->matricule_2->text());
            ui->tableView->setModel(E.afficher());
            ui->nom->setText("");
            ui->prenom->setText("");
            ui->cin->setText("");
            ui->adresse->setText("");
            ui->email->setText("");
            ui->tel->setText("");
            ui->date_embauche->setText("");
            ui->heure->setText("");
            ui->prix_heure->setText("");
            videz_label();


        }
        else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
        }
        else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                 QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_clicked()
{
    int matricule=ui->comboBox->currentIndex();
    QString nom=ui->nom_3->text();
    QString prenom=ui->prenom_3->text();
    int cin=ui->cin_3->text().toInt();
    QString adresse=ui->adresse_3->text();
    QString email=ui->email_3->text();
    int tel=ui->tel_3->text().toInt();
    QString date_embauche=ui->date_embauche_3->text();
    int heure=ui->heure_3->text().toInt();
    int prix_heure=ui->prix_heure_3->text().toInt();
    employe E(matricule,nom,prenom,cin,adresse,email,tel,date_embauche,heure,prix_heure);


        E.setmatricule(ui->comboBox->currentIndex()) ;
        bool test=E.modifier(E.getmatricule()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            ui->tableView->setModel(E.afficher());
            videz_label();
        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

/*void MainWindow::on_pushButton_3_clicked()
{
    employe E1; L1.matricule(ui->matricule_2->text().toInt());
    bool test=L1.supprimer(L1.getref_log());
    QMessageBox msgbox;
    if(test)
    {msgbox.setText("Suppression avec succes.");
        ui->tableView->setModel(L.afficher());
    }
    else
        msgbox.setText("Echec de suppression");
    msgbox.exec();
}
*/


void MainWindow::on_supprimer_clicked()
{
    employe E1; E1.setmatricule(ui->comboBox_2->currentText().toInt());
    bool test=E1.supprimer(E1.getmatricule());
    QMessageBox msgbox;
    /*if(test)
    {msgbox.setText("Suppression avec succes.");
        ui->tableView->setModel(E.afficher());
        videz_label();

    }
    else
        msgbox.setText("Echec de suppression");
    msgbox.exec();*/
        msgbox.setText("voulez-vous le supprimer ?");
        msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            ui->tableView->setModel(E.afficher());
            ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
            ui->comboBox->removeItem(ui->comboBox_2->currentIndex());
            videz_label();
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

void MainWindow::afficherBD()
{
employe afe;
ui->tableView->setModel(afe.afficher());
QSqlQuery qry;
qry.prepare("select matricule from employe");
qry.exec();
while(qry.next())
{
    ui->comboBox->addItem(qry.value("matricule").toString());
    ui->comboBox_2->addItem(qry.value("matricule").toString());
}

}
void MainWindow::videz_label()
{
    ui->matricule_2->setText("");
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->cin->setText("");
    ui->adresse->setText("");
    ui->email->setText("");
    ui->tel->setText("");
    ui->date_embauche->setText("");
    ui->heure->setText("");
    ui->prix_heure->setText("");
    ui->nom_3->setText("");
    ui->prenom_3->setText("");
    ui->cin_3->setText("");
    ui->adresse_3->setText("");
    ui->email_3->setText("");
    ui->tel_3->setText("");
    ui->date_embauche_3->setText("");
    ui->heure_3->setText("");
    ui->prix_heure_3->setText("");

}


void MainWindow::on_radioButton_4_clicked()
{
    ui->tableView->setModel(E.trinom());
}

void MainWindow::on_radioButton_5_clicked()
{
    ui->tableView->setModel(E.trimat());

}

void MainWindow::on_radioButton_6_clicked()
{
    ui->tableView->setModel(E.tridate());

}


void MainWindow::on_recher_edit2_textChanged(const QString &arg1)
{
    employe e;


    QString nom = ui->recher_edit2->text();
     QString matricule = ui->recher_edit2->text();
      QString date = ui->recher_edit2->text();
    e.recherche(ui->tableView,nom,matricule,date);
    if (ui->recher_edit2->text().isEmpty())
    {
       ui->tableView->setModel(e.afficher());
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery query;
        int matricule=ui->comboBox->currentIndex() ;
       query.prepare("Select * from employe where matricule=:matricule" );
               query.bindValue(0,matricule) ;
               query.exec();
        query.next() ;
       // F.FINANCE(FINANCE);
        ui->nom_3->setText(query.value("nom").toString());
        ui->prenom_3->setText(query.value("prenom").toString());
         ui->cin_3->setText(query.value(3).toString());
         ui->adresse_3->setText(query.value("adresse").toString());
         ui->email_3->setText(query.value("email").toString());
         ui->tel_3->setText(query.value(6).toString());
         ui->date_embauche_3->setText(query.value("date_embauche").toString());
         ui->heure_3->setText(query.value(8).toString());
         ui->prix_heure_3->setText(query.value(9).toString());


}

void MainWindow::on_afficher_liste_clicked()
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
                                           "<center> <H1>Liste des employes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->tableView->currentIndex().row()==-1)
                            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                     QObject::tr("Veuillez Choisir un contrat du Tableau.\n"
                                                                 "Click Ok to exit."), QMessageBox::Ok);
                        else
                        {
                             int  Code=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
                             const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
                             std::ofstream myfile;
                             myfile.open ("qrcode.svg") ;
                             myfile << qr.toSvgString(1);
                             myfile.close();
                             QSvgRenderer svgRenderer(QString("qrcode.svg"));
                             QPixmap pix( QSize(90, 90) );
                             QPainter pixPainter( &pix );
                             svgRenderer.render(&pixPainter);
                             ui->qrcode->setPixmap(pix);
                        }
}
