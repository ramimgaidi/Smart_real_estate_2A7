#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include "connection.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs << "english" << "espagnol" << "french" ;
    const QString lang = QInputDialog::getItem(NULL,
                                         "language",
                                         "select a language",
                                               langs);
if(lang == "espagnol"){
    T.load(":/espagnol.qm");
}else if(lang == "french"){
    T.load(":/french.qm");
}
if(lang != "english"){
    a.installTranslator(&T);
}
    a.setStyle("fusiion");
    MainWindow w;
    w.show();
    login l;
    l.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        w.afficherBD();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
