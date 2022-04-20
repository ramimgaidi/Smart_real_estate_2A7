#ifndef contrat_H
#define contrat_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
class calendrier
{
public:
calendrier();
calendrier(int ref_cle,QDate date_cle);
int getref_cle();
QDate getdate_cle();

void setref_cle(int);
void setdate_cle(QDate);

 QSqlQueryModel* afficher1();
 QSqlQueryModel* triasc();
 QSqlQueryModel* tridesc();

 bool ajouter1();
 bool reset();

 private:
 QDate date_cle;
 int ref_cle;
};

class contrat
{
public:
    contrat();

    contrat(int ref,QString nom,QString prenom,QString email,QDate dateN,int montant);

    int getref();
    QString getnom();
    QString getprenom();
    QDate getdateN();
    QString getemail();
    int getmontant();



    void setref(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_cle(QDate);
    void setdateN(QDate);
    void setemail(QString);
    void setref_cle(int);
    void setmontant(int);
    bool ajouter();

    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    int controle_saisieA(QString,QString);
    int controle_saisieB(QString);
    QSqlQueryModel* chercher(QString);
    QSqlQueryModel *rechercher(QString);


   /* void genPdfUser();*/
private:
    int ref,montant;
    QString nom,prenom,email;
    QDate dateN;

};


#endif // contrat_H
