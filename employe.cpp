#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"

employe::employe()
{
   matricule=0;nom=" ";prenom=" ";cin=0;adresse=" ";email=" ";tel=0;date_embauche=" ";heure=0;prix_heure=0;
}
employe::employe(int matricule,QString nom,QString prenom,int cin,QString adresse,QString email,int tel ,QString date_embauche,int heure,int prix_heure)
{this->matricule=matricule;this->nom=nom; this->prenom=prenom;  this->cin=cin; this->adresse=adresse; this->email=email ;this->tel=tel ;this->date_embauche=date_embauche ;this->heure=heure ;this->prix_heure=prix_heure ; }
int employe::getmatricule(){return matricule;}
QString employe::getnom(){return nom;}
QString employe::getprenom(){return prenom;}
int employe::getcin(){return cin;}
QString employe::getadresse(){return adresse;}
QString employe::getemail(){return email;}
int employe::gettel(){return tel;}
QString employe::getdate_embauche(){return date_embauche;}
int employe::getheure(){return heure;}
int employe::getprix_heure(){return prix_heure;}

void employe::setmatricule(int matricule){this->matricule=matricule;}
void employe::setnom(QString nom) {this->nom=nom;}
void employe::setprenom(QString prenom) {this->prenom=prenom;}
void employe::setcin(int cin){this->cin=cin;}
void employe::setadresse(QString adresse) {this->adresse=adresse;}
void employe::setemail(QString email) {this->email=email;}
void employe::settel(int tel){this->tel=tel;}
void employe::setdate_embauche(QString date_embauche) {this->date_embauche=date_embauche;}
void employe::setheure(int heure) {this->heure=heure;}
void employe::setprix_heure(int prix_heure) {this->prix_heure=prix_heure;}

bool employe::ajouter()
{
               QString matricule_string= QString::number(matricule);
               QString cin_string= QString::number(cin);
               QString tel_string= QString::number(tel);
               QString heure_string= QString::number(heure);
               QString prix_heure_string= QString::number(prix_heure);
               QSqlQuery query;
               if(controle_saisieA(nom,prenom) == -1)


          query.prepare("INSERT INTO employe (matricule, nom, prenom, cin, adresse, email, tel, date_embauche, heure, prix_heure  ) "
                        "VALUES (:matricule, :nom, :prenom, :cin, :adresse, :email, :tel, :date_embauche, :heure, :prix_heure)");


          query.bindValue(0, matricule_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, cin_string);
          query.bindValue(4, adresse);
          query.bindValue(5, email);
          query.bindValue(6, tel_string);
          query.bindValue(7, date_embauche);
          query.bindValue(8, heure_string);
          query.bindValue(9, prix_heure_string);

    return query.exec();
}
QSqlQueryModel* employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM employe");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));

          model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_embauche"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure"));
          model->setHeaderData(9, Qt::Horizontal, QObject::tr("prix_heure"));


    return model;
}
bool employe::modifier(int matricule)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update employe set  nom =:nom, prenom =:prenom, cin =:cin, adresse =:adresse,email =:email,tel =:tel,date_embauche =:date_embauche,heure =:heure,prix_heure =:prix_heure where matricule= :matricule ");

     query.bindValue(":matricule",matricule);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":cin", cin);
     query.bindValue(":adresse", adresse);
     query.bindValue(":email", email);
     query.bindValue(":tel", tel);
     query.bindValue(":date_embauche", date_embauche);
     query.bindValue(":heure", heure);
     query.bindValue(":prix_heure", prix_heure);
     return query.exec();
    }
bool employe::supprimer(int matricule)
{
    QSqlQuery query;
          query.prepare("Delete from employe where matricule=:matricule" );
          query.bindValue(0, matricule);
    return query.exec();
}

int employe::controle_saisieA(QString nom,QString prenom)
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
        if(nom.length() > 12 || prenom.length() > 20 )
        {
             QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs nom et prenom ne doit pas depassé 20 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if( nom.length() < 3 || prenom.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs nom et prenom doit etre supérieur a 3 caractére"),QMessageBox::Ok );
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
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""nom"""),QMessageBox::Ok );

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
                                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas caractéres spéciaux dans le champ ""Type"""),QMessageBox::Ok );

                                    j=caraspec.length();
                                    i=prenom.length();
                                    return 0;
                                }
                            }
                        }



    }
}
return -1;

}
QSqlQueryModel * employe::trinom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_embauche"));

    return model;
}
QSqlQueryModel * employe::trimat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY matricule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_embauche"));

    return model;
}



QSqlQueryModel * employe::tridate()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY date_embauche");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_embauche"));

    return model;
}

void employe :: recherche(QTableView * table ,QString nom, QString matricule,QString date_embauche )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EMPLOYE where NOM like '%"+nom+"%' or MATRICULE like '%"+matricule+"%' or DATE_EMBAUCHE like '%"+date_embauche+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();



}


