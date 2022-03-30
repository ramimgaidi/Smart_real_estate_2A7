#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{


           QString nom=ui->lineEdit_username->text();
           QString mdp=ui-> lineEdit_password->text();
           QSqlQuery query;
           query.prepare("select * from employe where nom=:nom and matricule=:mdp");
           query.addBindValue(ui->lineEdit_username->text());
           query.addBindValue(ui->lineEdit_password->text());
           query.exec();
               bool alreadyExist = false;
               alreadyExist = query.next();
               if(alreadyExist)
               {

                     ui->lineEdit_username->setText("");
                     ui->lineEdit_password->setText("");
                     close() ;
                    QMessageBox msgbox ;
                    msgbox.setText("Bienvenue "+nom+"") ;
                    msgbox.exec() ;


               }
               else
                   {
                   QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                    QObject::tr("NOM D'UTILISATEUR OU MOT DE PASSE INCORRECTE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->lineEdit_username->setText("");
                   ui->lineEdit_password->setText("");
                    }
    }


