#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
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

    ui->matricule_2->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->tableView->setModel(E.afficher());

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
    int matricule=ui->matricule_3->text().toInt();
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


        E.setmatricule(ui->matricule_3->text().toInt()) ;
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
    employe E1; E1.setmatricule(ui->matricule_4->text().toInt());
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

}
void MainWindow::videz_label()
{
    ui->matricule_4->setText("");
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
    ui->matricule_3->setText("");
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

