#include "widget.h"
#include "ui_widget.h"
#include "chatboxconnectiondialog.h"
#include <QTcpSocket>
#include <QTextStream>

namespace DuarteCorporation{
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    nSocket=new QTcpSocket(this);
    connect(nSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(nSocket);
        auto text=T.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
QTextStream T(nSocket);
T << ui->nickname-> text() << ": " << ui->message->text();
nSocket->flush();
ui->message->clear();
}

void Widget::on_bind_clicked()
{
ChatboxConnectionDialog D(this);
if(D.exec()==QDialog::Rejected)
{return;
}
nSocket->connectToHost(D.hostname(),D.port());
}
}
