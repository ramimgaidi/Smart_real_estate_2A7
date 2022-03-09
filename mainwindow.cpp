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
        int dispo_log=ui->lineEdit_18->text().toInt();
        Logement L(ref_log,type_log,adresse_log,surface_log,piece_log,dispo_log);
        bool test=L.ajouter();
        QMessageBox msgbox;
        if(ref_log!=0 &&  type_log.size()>0 &&  adresse_log.size()>0 && surface_log!=0 && piece_log!=0 && dispo_log!=0)
        {
        if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->tableView->setModel(L.afficher());
            ui->comboBox_2->setCurrentText("");
            ui->lineEdit->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_16->setText("");
            ui->lineEdit_17->setText("");
            ui->lineEdit_18->setText("");

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
void MainWindow::afficherBD()
{
Logement afe;
ui->tableView->setModel(afe.afficher());

}
