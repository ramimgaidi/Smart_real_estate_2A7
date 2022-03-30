#ifndef logement_H
#define logement_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
class Logement
{
public:
    Logement();
    Logement(int,QString,QString,int,int,QString);
    int getref_log();
    QString gettype_log();
    QString getadresse_log();
    int getsurface_log();
    int getpiece_log();
    QString getdispo_log();

    void setref_log(int);
    void settype_log(QString);
    void setadresse_log(QString);
    void setsurface_log(int);
    void setpiece_log(int);
    void setdispo_log(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel *tri_ref_log();
    QSqlQueryModel *tri_type_log();
    QSqlQueryModel *tri_piece_log();
    QSqlQueryModel *tri_dispo_log();

private:
    int ref_log,piece_log;
    QString type_log,adresse_log,dispo_log;
    int surface_log;
};


#endif // logement_H
