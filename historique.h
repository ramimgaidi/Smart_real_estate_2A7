#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QDateTime>


class historique
{
public:

    historique();
    void enregistrer_txt(QString,QString,QString,QString);
    QString imprimer_hist();


private:
    QString chaine;
};

#endif // HISTORIQUE_H
