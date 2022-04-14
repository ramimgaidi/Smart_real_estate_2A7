#include "logement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"

Logement::Logement()
{
   ref_log=0;type_log=" ";adresse_log=" ";surface_log=0;piece_log=0;dispo_log=" ";
}
Logement::Logement(int ref_log,QString type_log,QString adresse_log,int surface_log,int piece_log,QString dispo_log)
{this->ref_log=ref_log;this->type_log=type_log; this->adresse_log=adresse_log;  this->surface_log=surface_log;  this->piece_log=piece_log; this->dispo_log=dispo_log;}
int Logement::getref_log(){return ref_log;}
QString Logement::gettype_log(){return type_log;}
QString Logement::getadresse_log(){return adresse_log;}
int Logement::getsurface_log(){return surface_log;}
int Logement::getpiece_log(){return piece_log;}
QString Logement::getdispo_log(){return dispo_log;}
void Logement::setref_log(int ref_log){this->ref_log=ref_log;}
void Logement::settype_log(QString type_log){this->type_log=type_log;}
void Logement::setadresse_log(QString adresse_log){this->adresse_log=adresse_log;}
void Logement::setsurface_log(int surface_log){this->surface_log=surface_log;}
void Logement::setpiece_log(int piece_log){this->piece_log=piece_log;}
void Logement::setdispo_log(QString dispo_log){this->dispo_log=dispo_log;}

bool Logement::ajouter()
{

    QString ref_log_string= QString::number(ref_log);
    QString piece_log_string= QString::number(piece_log);
    QString surface_log_string= QString::number(surface_log);
    QSqlQuery query;
          query.prepare("INSERT INTO Logement (ref_log, type_log, adresse_log, surface_log, piece_log, dispo_log  ) "
                        "VALUES (:ref_log, :type_log, :adresse_log,  :surface_log, :piece_log, :dispolog)");
          query.bindValue(0, ref_log_string);
          query.bindValue(1, type_log);
          query.bindValue(2, adresse_log);
          query.bindValue(3, surface_log_string);
          query.bindValue(4, piece_log_string);
          query.bindValue(5, dispo_log);

    return query.exec();
}
QSqlQueryModel* Logement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM Logement");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_log"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_log"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface_log"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("piece_log"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("dispo_log"));
    return model;
}
bool Logement::modifier(int ref_log)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update Logement set  type_log= :type_log , adresse_log= :adresse_log, surface_log =:surface_log, piece_log =:piece_log, dispo_log =:dispo_log where ref_log= :ref_log ");

     query.bindValue(":ref_log",ref_log);
     query.bindValue(":type_log", type_log);
     query.bindValue(":adresse_log", adresse_log);
     query.bindValue(":surface_log", surface_log);
     query.bindValue(":piece_log", piece_log);
     query.bindValue(":dispo_log", dispo_log);
    return query.exec();
    }
bool Logement::supprimer(int ref_log)
{
    QSqlQuery query;
          query.prepare("Delete from Logement where ref_log=:ref_log" );
          query.bindValue(0, ref_log);
    return query.exec();
}
QSqlQueryModel *Logement::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Logement WHERE ref_log  LIKE'%"+rech+"%' or type_log  LIKE'%"+rech+"%' or dispo_log  LIKE'%"+rech+"%' "); //recherche avance par reference, type et disponibilité
    return model;
}
QSqlQueryModel *Logement::tri_ref_log()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Logement order by ref_log" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_log"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface_log"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("piece_log"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("dispo_log"));

    return model;

}
QSqlQueryModel *Logement::tri_type_log()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Logement order by type_log" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_log"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface_log"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("piece_log"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("dispo_log"));

    return model;

}
QSqlQueryModel *Logement::tri_piece_log()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Logement order by piece_log" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_log"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface_log"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("piece_log"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("dispo_log"));

    return model;

}
QSqlQueryModel *Logement::tri_dispo_log()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Logement order by dispo_log" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_log"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface_log"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("piece_log"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("dispo_log"));

    return model;

}

