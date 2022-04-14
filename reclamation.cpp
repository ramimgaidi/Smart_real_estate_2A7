#include "reclamation.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPainter>
#include <QTextEdit>
#include <QTextCursor>
reclamation::reclamation()
{
ref_rec=0;
ref_log=0;

}

reclamation::reclamation(int ref_rec,int ref_log,QString type_panne,QString description)
{
   this->ref_rec=ref_rec;this->ref_log=ref_log;this->type_panne=type_panne;this->description=description;
}

int reclamation::getref_rec(){return ref_rec;}
int reclamation::getref_log(){return ref_log;}
QString reclamation::gettype_panne(){return type_panne;}
QString reclamation::getdescription(){return description;}
void reclamation::setref_rec(int ref_rec){this->ref_rec=ref_rec;}
void reclamation::setref_log(int ref_log){this->ref_log=ref_log;}
void reclamation::settype_panne(QString type_panne){this->type_panne=type_panne;}
void reclamation::setdescription(QString description){this->description=description;}



bool reclamation::ajouter()
{
    QString ref_rec_string=QString::number(ref_rec);

        QSqlQuery query;
        if(controle_saisieA(type_panne,description))
        query.prepare("INSERT INTO MAINTENANCE (ref_rec,ref_log , type_panne , description) "
                       "VALUES (:ref_rec,:ref_log , :type_panne , :description)");
         query.bindValue(0, ref_rec_string);
         query.bindValue(1, ref_log);
         query.bindValue(2, type_panne);
         query.bindValue(3, description);
         return  query.exec();
    }

QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;
          model->setQuery("SELECT* FROM maintenance");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_rec"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref_log"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_panne"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));

    return model;  
}
QSqlQueryModel* reclamation::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel;
          model->setQuery("SELECT ref_log FROM LOGEMENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_log"));


    return model;
}

bool reclamation::modifier(int ref_rec)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     if(controle_saisieA2(type_panne,description))
    query.prepare("Update maintenance set  ref_log= :ref_log,type_panne= :type_panne, description =:description where ref_rec= :ref_rec ");

     query.bindValue(":ref_rec",ref_rec);
     query.bindValue(":ref_log",ref_log);
     query.bindValue(":type_panne", type_panne);
     query.bindValue(":description", description);
    return query.exec();
    }



bool reclamation::supprimer(int ref_rec)
{
    QSqlQuery query;
          query.prepare("Delete from maintenance where ref_rec=:ref_rec" );
          query.bindValue(0, ref_rec);
    return query.exec();
}

int reclamation::controle_saisieA(QString type_panne,QString description)
{
if(type_panne == "" && description == "")
{
    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Tout les champ sont vide !"),QMessageBox::Ok );
    return 0;
}
else
{
    if( type_panne == "" || description == "")
    {
         QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Il y a un/des champ/s qui sont vide !"),QMessageBox::Ok );
         return 0;
    }
    else
    {
        if(type_panne.length() > 20 || description.length() > 20 )
        {
             QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs ne doit pas depassé 20 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if( type_panne.length() < 3 || description.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs doit etre supérieur a 3 caractére"),QMessageBox::Ok );
            return 0;
        }
        int i;
        int j;
        QString caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?0123456789";
        for(i=0;i<type_panne.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(type_panne[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""type_panne auteur"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=type_panne.length();
                    return 0;
                }
            }
        }
        caraspec = "~""#'{([-|`_\^@)]=+}$£¤¨*!§:/;";
        for(i=0;i<type_panne.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(type_panne[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("pas de caractéres spéciaux dans le champ ""type_panne articles"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=type_panne.length();
                    return 0;
                }
            }
        }
        caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";

                caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";
                        for(i=0;i<description.length();i++)
                        {
                            for(j=0;j<caraspec.length();j++)
                            {
                                if(description[i] == caraspec[j] )
                                {
                                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas caractéres spéciaux dans le champ ""Type"""),QMessageBox::Ok );

                                    j=caraspec.length();
                                    i=description.length();
                                    return 0;
                                }
                            }
                        }




    }
}
return -1;

}


int reclamation::controle_saisieA2(QString type_panne,QString description)
{
if(type_panne == "" && description == "")
{
    QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("Tout les champ sont vide !"),QMessageBox::Ok );
    return 0;
}
else
{
    if( type_panne == "" || description == "")
    {
         QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("Il y a un/des champ/s qui sont vide !"),QMessageBox::Ok );
         return 0;
    }
    else
    {
        if(type_panne.length() > 20 || description.length() > 20 )
        {
             QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("La taille des champs ne doit pas depassé 20 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if( type_panne.length() < 3 || description.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("La taille des champs doit etre supérieur a 3 caractére"),QMessageBox::Ok );
            return 0;
        }
        int i;
        int j;
        QString caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?0123456789";
        for(i=0;i<type_panne.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(type_panne[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""type_panne auteur"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=type_panne.length();
                    return 0;
                }
            }
        }
        caraspec = "~""#'{([-|`_\^@)]=+}$£¤¨*!§:/;";
        for(i=0;i<type_panne.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(type_panne[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("pas de caractéres spéciaux dans le champ ""type_panne articles"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=type_panne.length();
                    return 0;
                }
            }
        }
        caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";

                caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";
                        for(i=0;i<description.length();i++)
                        {
                            for(j=0;j<caraspec.length();j++)
                            {
                                if(description[i] == caraspec[j] )
                                {
                                    QMessageBox::critical(nullptr,QObject::tr("modifier") , QObject::tr("Pas caractéres spéciaux dans le champ ""Type"""),QMessageBox::Ok );

                                    j=caraspec.length();
                                    i=description.length();
                                    return 0;
                                }
                            }
                        }




    }
}
return -1;

}

QSqlQueryModel *reclamation::tri_ref_rec()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from maintenance order by ref_rec" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_rec"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_panne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));


    return model;

}

QSqlQueryModel *reclamation::tri_type_panne()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from maintenance order by type_panne" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_rec"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_panne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));

    return model;

}

QSqlQueryModel *reclamation::tri_ref_log()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from maintenance order by ref_log" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_rec"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref_log"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_panne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));

    return model;

}
QSqlQueryModel *reclamation::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM maintenance WHERE ref_rec  LIKE'%"+rech+"%' or ref_log  LIKE'%"+rech+"%' or type_panne  LIKE'%"+rech+"%' or description  LIKE'%"+rech+"%'  ");
    return model;
}
void pdf(QString filename)
{
QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    printer.setPageMargins(QMarginsF(30, 30, 30, 30));

    QFont headerFont("Times New Roman", 8);
    QFont titleFont("Times New Roman", 14, QFont::Bold);

    QTextCharFormat txtformat = QTextCharFormat();


    QTextDocument doc;
    doc.setPageSize(printer.pageRect().size());

    QTextCursor* cursor = new QTextCursor(&doc);

    txtformat.setFont(headerFont);
    cursor->insertText("Company XYZ", txtformat);


    doc.print(&printer);
}
