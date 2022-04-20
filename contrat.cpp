#include "contrat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QTextBrowser>
#include <QPrinter>
#include <QPrintDialog>
#include <QDesktopServices>
#include "connection.h"
calendrier::calendrier()
{
    ref_cle=0;
    date_cle=QDate();
}
calendrier::calendrier(int ref_cle,QDate date_cle)
{
    this->ref_cle=ref_cle; this->date_cle=date_cle;
}
int calendrier::getref_cle(){return ref_cle;}
QDate calendrier::getdate_cle(){return date_cle;}
void calendrier::setref_cle(int ref_cle){this->ref_cle=ref_cle;}
void calendrier::setdate_cle(QDate date_cle){this->date_cle=date_cle;}

contrat::contrat()
{
    ref=0;

    montant=0;
    nom=" ";
    prenom=" ";
    email=" ";
    dateN=QDate();

}
    contrat::contrat(int ref,QString nom,QString prenom,QString email,QDate dateN,int montant)
   { this->ref=ref; this->nom=nom;this->prenom=prenom;this->email=email;this->dateN=dateN;this->montant=montant;}
int contrat::getref(){return ref;}
QString contrat::getnom(){return nom;}
QString contrat::getprenom(){return prenom;}
QString contrat::getemail(){return email;}
QDate contrat::getdateN(){return dateN;}
int contrat::getmontant(){return montant;}
void contrat::setref(int ref){this->ref=ref;}
void contrat::setnom(QString nom){this->nom=nom;}
void contrat::setprenom(QString prenom){this->prenom=prenom;}
void contrat::setemail(QString email){this->email=email;}
void contrat::setdateN(QDate dateN){this->dateN=dateN;}
void contrat::setmontant(int montant){this->montant=montant;}
bool contrat::ajouter()
{
    QString ref_string= QString::number(ref);
                QString montant_string= QString::number(montant);
    QSqlQuery query;
    if(controle_saisieA(nom,prenom) == -1)
          query.prepare("INSERT INTO contrat (ref, nom, prenom,dateN,email,montant ) "
                        "VALUES (:ref, :nom, :prenom,  :dateN,:email,:montant)");
          query.bindValue(0, ref_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, dateN);
          query.bindValue(4, email);
          query.bindValue(5, montant_string);

    return query.exec();
}
QSqlQueryModel* contrat::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM contrat");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateN"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("montant"));
    return model;
}

bool contrat::modifier(int ref)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update contrat set  nom= :nom , prenom= :prenom, dateN =:dateN, email =:email, montant =:montant  where ref= :ref ");

     query.bindValue(":ref",ref);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":dateN", dateN);
     query.bindValue(":email", email);
     query.bindValue(":montant",montant);
    return query.exec();
    }
bool contrat::supprimer(int ref)
{
    QSqlQuery query;
          query.prepare("Delete from contrat where ref=:ref" );
          query.bindValue(0, ref);
    return query.exec();
}

/*void contrat::genPdfUser()
{
    QSqlQuery query("SELECT * FROM user");
    QString champ("UPI   | First Name   |  Last Name   | COS   \n");
    while (query.next())
    {
        for(int fieldNo=0; fieldNo<4; fieldNo++)
        {
            champ += query.value(fieldNo).toString()+"  |";
        };
        champ+="\n";
    };
    QTextDocument *ftemp=new QTextDocument(champ);

    QString filename="users.pdf";
    //Paramètres d'impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFileName(filename);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);

    ftemp->print(&printer);
    if(!QDesktopServices::openUrl(QUrl::fromLocalFile("users.pdf")))
            {
      QMessageBox::critical(nullptr, QObject::tr("ERROR"),QObject::tr("Impossible d'ouvrir le fichier...."),QMessageBox::Cancel);
            };
}*/

int contrat::controle_saisieA(QString nom,QString prenom)
{
if(nom == "" && prenom == "")
{
    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Tout les champ sont vide !"),QMessageBox::Ok );
    return 0;
}
else
{
    if( nom == "" || prenom == "")
    {
         QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Il y a un/des champ/s qui sont vide !"),QMessageBox::Ok );
         return 0;
    }
    else
    {
        if(nom.length() > 12 || prenom.length() > 12 )
        {
             QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs ne doit pas depassé 12 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if( nom.length() < 3 || prenom.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs doit etre supérieur a 3 caractére"),QMessageBox::Ok );
            return 0;
        }
        int i;
        int j;
        QString caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?0123456789";
        for(i=0;i<nom.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(nom[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""Nom"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=nom.length();
                    return 0;
                }
            }
        }
        caraspec = "~""#'{([-|`_\^@)]=+}$£¤¨*!§:/;";
        for(i=0;i<nom.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(nom[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("pas de caractéres spéciaux dans le champ ""Nom articles"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=nom.length();
                    return 0;
                }
            }
        }
        caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";

                caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";
                        for(i=0;i<prenom.length();i++)
                        {
                            for(j=0;j<caraspec.length();j++)
                            {
                                if(prenom[i] == caraspec[j] )
                                {
                                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas caractéres spéciaux dans le champ ""prenom"""),QMessageBox::Ok );

                                    j=caraspec.length();
                                    i=prenom.length();
                                    return 0;
                                }
                            }
                        }

}
return -1;

}}
int contrat::controle_saisieB(QString email)
{/* int i,j;
    QString caraspec = "@";
            for(i=0;i<email.length();i++)
            {
                for(j=0;j<caraspec.length();j++)
                {
                    if(email[i] != caraspec[j] )
                    {
                        QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("il faut mettre @ dans votre ""email"""),QMessageBox::Ok );

                        j=caraspec.length();
                        i=email.length();
                        return 1;
                    }
                    else if (email[i] == caraspec[j])
                    {
                        j=caraspec.length();
                        i=email.length();
                        return 0;}
                }
            }
            return -1;*/
}
QSqlQueryModel* contrat::chercher(QString nom)
{/*
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from contrat where nom= ? ");
    query.addBindValue(nom);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("dateN"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));



  return model;*/
}
QSqlQueryModel *contrat::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM contrat WHERE ref LIKE'%"+rech+"%' or nom LIKE'%"+rech+"%' or prenom LIKE'%"+rech+"%'" );
    return model;


}

QSqlQueryModel* calendrier::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM calendrier");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_cle"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_cle"));

    return model;
}
QSqlQueryModel* calendrier::triasc()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM calendrier ORDER BY ref_cle ASC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_cle"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_cle"));

    return model;
}
QSqlQueryModel* calendrier::tridesc()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM calendrier ORDER BY ref_cle DESC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_cle"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_cle"));

    return model;
}

bool calendrier::ajouter1()
{
    QString ref_cle_string= QString::number(ref_cle);

    QSqlQuery query;

          query.prepare("INSERT INTO calendrier (ref_cle, date_cle ) "
                        "VALUES (:ref_cle, :date_cle)");
          query.bindValue(0, ref_cle_string);
          query.bindValue(1,date_cle);


    return query.exec();
}


