#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator   ( new QIntValidator(0, 999, this));
    ui->lineEdit_16->setValidator( new QIntValidator(1, 99999999, this));
    ui->lineEdit_17->setValidator( new QIntValidator(1, 7, this));
    ui->lineEdit_19->setValidator( new QIntValidator(1, 99999999, this));
    ui->lineEdit_20->setValidator( new QIntValidator(1, 7, this));
    ui->comboBox_5->addItem("");
    ui->comboBox_6->addItem("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        int ref_log=ui->lineEdit->text().toInt();
        QString type_log=ui->comboBox_2->currentText();
        QString adresse_log=ui->lineEdit_3->text();
        int surface_log=ui->lineEdit_16->text().toInt();
        int piece_log=ui->lineEdit_17->text().toInt();
        QString dispo_log=ui->comboBox_3->currentText();
        Logement L(ref_log,type_log,adresse_log,surface_log,piece_log,dispo_log);
        bool test=L.ajouter();
        QMessageBox msgbox;
        if(ref_log!=0 &&  type_log.size()>0 &&  adresse_log.size()>0 && surface_log!=0 && piece_log!=0 && dispo_log.size()>0)
        {
        if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->comboBox_5->addItem(ui->lineEdit->text());
            ui->comboBox_6->addItem(ui->lineEdit->text());
            ui->tableView->setModel(L.afficher());
            ui->comboBox_2->setCurrentText("");
            ui->lineEdit->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_16->setText("");
            ui->lineEdit_17->setText("");
            ui->comboBox_3->setCurrentText("");

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
    int ref_log=ui->comboBox_5->currentIndex();
    QString type_log=ui->comboBox->currentText();
    QString adresse_log=ui->lineEdit_6->text();
    int surface_log=ui->lineEdit_19->text().toInt();
    int piece_log=ui->lineEdit_20->text().toInt();
    QString dispo_log=ui->comboBox_4->currentText();
    Logement L(ref_log,type_log,adresse_log,surface_log,piece_log,dispo_log);


        L.setref_log(ui->comboBox_5->currentIndex());
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
    Logement L1; L1.setref_log(ui->comboBox_6->currentText().toInt());
    bool test=L1.supprimer(L1.getref_log());
    QMessageBox msgbox;
    msgbox.setText("voulez-vous le supprimer ?");
        msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            ui->tableView->setModel(L.afficher());
            ui->comboBox_6->removeItem(ui->comboBox_6->currentIndex());
            ui->comboBox_5->removeItem(ui->comboBox_6->currentIndex());

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
Logement afe;
ui->tableView->setModel(afe.afficher());
QSqlQuery qry;
qry.prepare("select ref_log from logement");
qry.exec();
while(qry.next())
{
    ui->comboBox_5->addItem(qry.value("ref_log").toString());
    ui->comboBox_6->addItem(qry.value("ref_log").toString());
}

}

void MainWindow::on_comboBox_5_activated(const QString &arg2)
{
       QSqlQuery query;
       int ref_log=ui->comboBox_5->currentIndex();
       query.prepare("Select * from logement where ref_log=:ref_log" );
       query.bindValue(0,ref_log) ;
       query.exec();
       query.next();
      // L.logement(logement);
       ui->comboBox->setCurrentText(query.value("type_log").toString());
       ui->lineEdit_6->setText(query.value(2).toString());
       ui->lineEdit_19->setText(query.value(3).toString());
       ui->lineEdit_20->setText(query.value(4).toString());
       ui->comboBox_4->setCurrentText(query.value("dispo_log").toString());
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(L.rechercher(arg1));
}

void MainWindow::on_pushButton_4_clicked()
{
    Logement L;
        QString crit=ui->comboBox_7->currentText();
        if(crit=="ref_log")
        {
            ui->tableView->setModel(L.tri_ref_log());

        }
        else if(crit=="piece_log")
        {
            ui->tableView->setModel(L.tri_piece_log());
        }
        else if(crit=="type_log")
        {
            ui->tableView->setModel(L.tri_type_log());
        }
        else if(crit=="dispo_log")
        {
            ui->tableView->setModel(L.tri_dispo_log());
        }
           }
