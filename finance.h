#ifndef FINANCE_H
#define FINANCE_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
class Finance
{
public:
    Finance();
    Finance(int,QString,int,QDate);
    int getid_finance();
    int getrevenance();
    QString gettype_trans();
    QDate getdatee();

    void setid_finance(int);
    void setrevenance(int);
    void settype_trans(QString);
    void setdatee(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    void notification(QString);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    bool DateValide(QDate);
    QSqlQueryModel *tri_id_finance();
    QSqlQueryModel *tri_type_trans();
    QSqlQueryModel *rechercher(QString);
    int calcule_revenance(Finance);
    QSqlQueryModel *tri_id_2_finance();

private:
    int id_finance,revenance;
    QString type_trans;
    QDate datee;

};


#endif // FINANCE_H
