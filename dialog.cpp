#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include "Arduino1.h"
#include <QSqlQuery>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    //QSqlQuery query;
             //query.prepare("DELETE FROM arduino");
             // query.exec();
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    serialBuffer="";
    bool arduino_is_available=false;
    QString arduino_uno_port_name;
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier()== arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier()== arduino_uno_vendor_id)){
                arduino_is_available = true;
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }
    if(arduino_is_available){
        qDebug() << "Found the arduino port ...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this,"Serial Port Error","Couldn't open serial port to arduino");
    }
}

Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}
void Dialog::readSerial()
{ QStringList bufferSplit = serialBuffer.split(",");
    if(bufferSplit.length() <2){
serialData = arduino->readAll();
serialBuffer += QString::fromStdString(serialData.toStdString());
    }else{
        qDebug() << bufferSplit;
        Dialog::update_lcd(bufferSplit[0]);
        serialBuffer="";

}
    if(bufferSplit[0]=="1")
    {
        QString d1 = QDateTime::currentDateTime().toString();
                arduino1 a1(d1);
                a1.ajouter();
    }
}
void Dialog::update_label()
{

}
void Dialog::update_lcd(const QString sensor_reading)
{
ui->lcdNumber->display(sensor_reading);
}
bool arduino1::ajouter()
{

    QSqlQuery query;
          query.prepare("INSERT INTO arduino  DATE_AJOUT "
                        "VALUES ( :DATE_AJOUT)");

          query.bindValue(0, date_ajout);
          return  query.exec();
}
