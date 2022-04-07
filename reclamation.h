#ifndef reclamation_H
#define reclamation_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
class reclamation
{
public:

    reclamation();
     reclamation(int,int,QString,QString);
     int getref_rec();
     int getref_log();
     QString gettype_panne();
     QString getdescription();

     void setref_rec(int);
     void setref_log(int);
    void settype_panne(QString);
    void setdescription(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher2();
    bool supprimer(int);
    bool modifier(int);
int controle_saisieA(QString,QString );
int controle_saisieA2(QString,QString );
QSqlQueryModel *tri_ref_rec();
   QSqlQueryModel *tri_type_panne();
 QSqlQueryModel *rechercher(QString);
private:
    int ref_rec,ref_log;
    QString type_panne,description;
};



#endif // RECLAMATION_H
