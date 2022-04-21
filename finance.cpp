#include "finance.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
#include <QSystemTrayIcon>

QSqlQueryModel *Finance::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM finance WHERE ID_FINANCE  LIKE'%"+rech+"%' or type_trans  LIKE'%"+rech+"%' or revenance  LIKE'%"+rech+"%' or datee  LIKE'%"+rech+"%' ");
    return model;
}

Finance::Finance()
{
   id_finance=0;revenance=0;type_trans=" ";datee=QDate();
}
Finance::Finance(int id_finance,QString type_trans,int revenance,QDate datee)
{this->id_finance=id_finance;this->type_trans=type_trans; this->revenance=revenance;  this->datee=datee;}
int Finance::getid_finance(){return id_finance;}
QString Finance::gettype_trans(){return type_trans;}
int Finance::getrevenance(){return revenance;}
QDate Finance::getdatee(){return datee;}
void Finance::setid_finance(int id_finance){this->id_finance=id_finance;}
void Finance::settype_trans(QString type_trans){this->type_trans=type_trans;}
void Finance::setrevenance(int revenance){this->revenance=revenance;}
void Finance::setdatee(QDate datee){this->datee=datee;}
bool Finance::ajouter()
{

    QString id_finance_string= QString::number(id_finance);
                QString revenance_string= QString::number(revenance);
    QSqlQuery query;
          query.prepare("INSERT INTO FINANCE (ID_FINANCE, TYPE_TRANS, REVENANCE,DATEE ) "
                        "VALUES (:ID_FINANCE, :TYPE_TRANS, :REVENANCE,  :DATEE)");
          query.bindValue(0, id_finance_string);
          query.bindValue(1, type_trans);
          query.bindValue(2, revenance_string);
          query.bindValue(3, datee);

    return query.exec();
}
QSqlQueryModel* Finance::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM FINANCE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_TRANS"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENANCE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}
bool Finance::modifier(int id_finance)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update FINANCE set  TYPE_TRANS= :TYPE_TRANS , REVENANCE= :REVENANCE, DATEE =:DATEE where ID_FINANCE= :ID_FINANCE ");

     query.bindValue(":ID_FINANCE",id_finance);
     query.bindValue(":TYPE_TRANS", type_trans);
     query.bindValue(":REVENANCE", revenance);
     query.bindValue(":DATEE", datee);
    return query.exec();
    }
bool Finance::supprimer(int id_finance)
{
    QSqlQuery query;
          query.prepare("Delete from FINANCE where ID_FINANCE=:ID_FINANCE" );
          query.bindValue(0, id_finance);
    return query.exec();
}
//void Finance::notification(QString cls)
//{
   // QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    //notifyIcon->show();
    //notifyIcon->showMessage("NOTIFICATION",cls,QSystemTrayIcon::Information,15000);
  //  QSound newMessage(":/mixkit-positive-interface-beep-221.wav");
   // newMessage.play();

void Finance::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select REVENANCE from FINANCE");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }

}
QSqlQueryModel *Finance::tri_id_finance()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from finance order by ID_FINANCE ASC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_TRANS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

    return model;

}
QSqlQueryModel *Finance::tri_id_2_finance()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from finance order by ID_FINANCE DESC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_TRANS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

    return model;

}


QSqlQueryModel *Finance::tri_type_trans()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from finance order by type_trans" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_TRANS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

 return model;

}
bool Finance::DateValide(QDate Datee)

    {

        if (Datee>QDate::currentDate())

           {return false;}

        else return true;

    }

int Finance::calcule_revenance(Finance F)
{
    int tot=0;
    QSqlQuery q;
    q.prepare("select revenance from FINANCE ");
    q.exec();
        while(q.next())
        {
            tot=tot+q.value("revenance").toInt();
        }
    QString totale=QString::number(tot);
    QMessageBox msgbox ;
   msgbox.setText("la revenance total est :"+totale+"");
   msgbox.exec() ;
   return tot;
}
bool Finance::recherche_ref(QString MATRICULE)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("Select * from employe where MATRICULE=:MATRICULE");
    query.bindValue(":MATRICULE", MATRICULE);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        return false;
    }
}
