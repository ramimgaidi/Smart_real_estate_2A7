#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "widget.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include "DuMessengerServer.h"
#include "dialog.h"
using namespace DuarteCorporation;
using namespace ramymgaidi;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    Dialog x;
        //x.setFixedSize(434,122);
        x.setWindowTitle("temp sensor");
        x.show();
    a.setStyle("fusion");
    //Widget W;
    bool test=c.createconnect();

    if(test)
    {w.show();
       //W.show();
        w.afficherBD();
        w.afficherBD1();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    DuMessengerServer Server;
    if(!Server.startServer(3333)){
    qDebug()<<"error:" << Server.errorString();
    return 1;
    }
    qDebug() << "Server started ...";
    return a.exec();
}
