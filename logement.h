#ifndef logement_H
#define logement_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
class Logement
{
public:
    Logement();
    Logement(int,QString,QString,int,int,int);
    int getref_log();
    QString gettype_log();
    QString getadresse_log();
    int getsurface_log();
    int getpiece_log();
    int getdispo_log();

    void setref_log(int);
    void settype_log(QString);
    void setadresse_log(QString);
    void setsurface_log(int);
    void setpiece_log(int);
    void setdispo_log(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
private:
    int ref_log,piece_log,dispo_log;
    QString type_log,adresse_log;
    int surface_log;
};


#endif // logement_H
