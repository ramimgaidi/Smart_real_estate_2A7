#ifndef employe_H
#define employe_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>

class employe
{
public:
    employe();
    employe(int,QString,QString,int,QString,QString,int,QString,int,int);
    int getmatricule();
    QString getnom();
    QString getprenom();
    int getcin();
    QString getadresse();
    QString getemail();
    int gettel();
    QString getdate_embauche();
    int getheure();
    int getprix_heure();
    void setmatricule(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void setadresse(QString);
    void setemail(QString);
    void settel(int);
    void setdate_embauche(QString);
    void setheure(int);
    void setprix_heure(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
   // bool modifier(int,QString,QString,int,QString,QString,int,QString);
    bool modifier(int);
    int controle_saisieA(QString,QString);
    QSqlQueryModel* trinom();
        QSqlQueryModel* trimat();
        QSqlQueryModel* tridate();
        void recherche(QTableView * tabl, QString,QString,QString);

private:
    QString nom,prenom,adresse,email,date_embauche;
    int matricule,tel,cin,heure,prix_heure;

};


#endif // logement_H
