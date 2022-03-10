#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
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
    ui->lineEdit->setValidator( new QIntValidator(0, 99999999, this));
        ui->lineEdit_4->setValidator( new QIntValidator(0, 99999999, this));
        ui->lineEdit_7->setValidator( new QIntValidator(0, 99999999, this));
        ui->lineEdit_2->setValidator( new QIntValidator(0, 99999999, this));
        ui->lineEdit_5->setValidator( new QIntValidator(0, 99999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int ref_rec=ui->lineEdit->text().toInt();
    int ref_log=ui->lineEdit_2->text().toInt();
     QString type_panne=ui->lineEdit_3->text();
     QString description=ui->lineEdit_11->text();
    reclamation R(ref_rec, ref_log, type_panne , description);
     bool test=R.ajouter();
    QMessageBox msgbox;
    if(ref_rec!=0 && ref_log!=0 && type_panne.size()>0 && description.size()>0 )
    {
    if(test)
    {msgbox.setText("Ajout avec succes.");

        ui->tableView->setModel(R.afficher());
          ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
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
    int ref_rec=ui->lineEdit_4->text().toInt();
        int ref_log=ui->lineEdit_5->text().toInt();
        QString type_panne=ui->lineEdit_6->text();
        QString description=ui->lineEdit_12->text();
        reclamation R(ref_rec,ref_log,type_panne,description);



               ; R.setref_rec(ui->lineEdit_4->text().toInt()) ;
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
   reclamation R; R.setref_rec(ui->lineEdit_7->text().toInt());
    bool test=R.supprimer(R.getref_rec());
    QMessageBox msgbox;
    msgbox.setText("voulez-vous le supprimer ?");
        msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            ui->tableView->setModel(R.afficher());

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
