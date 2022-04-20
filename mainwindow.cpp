#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contrat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include <QApplication>
#include <QVideoWidget>
#include <QSlider>
#include <QProgressBar>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include "connection.h"
#include "widget.h"
#include "qrcode.h"
#include "qrwidget.h"


#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator( new QIntValidator(0, 9999, this));

        ui->lineEdit_12->setValidator( new QIntValidator(0, 9999999, this));
        ui->lineEdit_15->setValidator( new QIntValidator(0, 9999999, this));
        ui->comboBox->addItem("");
            ui->comboBox_2->addItem("");
            ui->comboBox_3->addItem("");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int ref=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QDate dateN=ui->dateEdit->date();
    QString email=ui->lineEdit_11->text();
    int montant=ui->lineEdit_12->text().toInt();
    contrat C(ref,nom,prenom,email,dateN,montant);
    bool test=C.ajouter();
    QMessageBox msgbox;
    if(ref!=0 && montant!=0 && nom.size()>0)
    {
    if(test)
    {msgbox.setText("Ajout avec succes.");
        ui->comboBox->addItem(ui->lineEdit->text());
        ui->comboBox_2->addItem(ui->lineEdit->text());
        ui->comboBox_3->addItem(ui->lineEdit->text());

        ui->tableView->setModel(C.afficher());
        ui->lineEdit_2->text();
        ui->lineEdit->text();
        ui->lineEdit_12->text();
videz_label();
    }
    else
        msgbox.setText("Echec d'ajout");
    msgbox.exec();
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                             QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_pushButton_2_clicked()
{
    int ref=ui->comboBox->currentIndex();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_6->text();
    QDate dateN=ui->dateEdit_2->date();
    QString email=ui->lineEdit_14->text();
    int montant=ui->lineEdit_15->text().toInt();

        contrat C(ref,nom,prenom,email,dateN,montant);

        C.setref(ui->comboBox->currentIndex()) ;
        bool test=C.modifier(C.getref()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            ui->tableView->setModel(C.afficher());
            videz_label();
        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    contrat C1; C1.setref(ui->comboBox_2->currentText().toInt());
    bool test=C1.supprimer(C1.getref());
    QMessageBox msgbox;
    msgbox.setText("voulez-vous le supprimer ?");
    msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgbox.exec();
    switch (ret) {
    case QMessageBox::Ok:
        ui->tableView->setModel(C.afficher());
        ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
        ui->comboBox->removeItem(ui->comboBox_2->currentIndex());
        videz_label();
        msgbox.setText("Suppression avec succes...");
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.exec();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        break;
    default:
        // should never be reached
        break;
  }
    }

    /*if(test)
    {
        msgbox.setText("Suppression avec succes...");
        ui->tableView->setModel(C.afficher());
        videz_label();
    }
    else
        msgbox.setText("Echec de suppression");
    msgbox.exec();
}*/

void MainWindow::afficherBD()
{

contrat afe;
ui->tableView->setModel(afe.afficher());
QSqlQuery qry;
qry.prepare("select ref from contrat");
qry.exec();
while(qry.next())
{
    ui->comboBox->addItem(qry.value("ref").toString());
    ui->comboBox_2->addItem(qry.value("ref").toString());
     ui->comboBox_3->addItem(qry.value("ref").toString());

}
}
void MainWindow::afficherBD1()
{

calendrier af;
ui->tableView_2->setModel(af.afficher1());
QSqlQuery qry;
qry.prepare("select ref_cle from calendrier");
qry.exec();
while(qry.next())
{
    //ui->comboBox->addItem(qry.value("ref").toString());
    //ui->comboBox_2->addItem(qry.value("ref").toString());

}
}
void MainWindow::videz_label()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");

    ui->dateEdit->date();
    ui->dateEdit_5->date();
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->dateEdit_2->date();
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
}




/*void MainWindow::on_pushButton_4_clicked()
{

    C.genPdfUser();

}*/

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery query;
        int ref=ui->comboBox->currentIndex() ;
       query.prepare("Select * from contrat where ref=:ref" );
               query.bindValue(0,ref) ;
               query.exec();
        query.next() ;
        ui->lineEdit_5->setText(query.value("nom").toString());
        ui->lineEdit_6->setText(query.value("prenom").toString());
        ui->lineEdit_14->setText(query.value("email").toString());
        ui->lineEdit_15->setText(query.value(5).toString());
        //ui->dateEdit_2->setDate(query.value(5).toDate());
        ui->dateEdit_2->setDate(query.value("dateN").toDate());

}

void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                       const int rowCount = ui->tableView->model()->rowCount();
                       const int columnCount = ui->tableView->model()->columnCount();
                      out <<  "<html>\n"
                      "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("strTitle")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"

                                      //     "<align='right'> " << datefich << "</align>"
                                       "<center> <H1>Liste des Contrats</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                   // headers
                                   out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                   out<<"<cellspacing=10 cellpadding=3>";
                                   for (int column = 0; column < columnCount; column++)
                                       if (!ui->tableView->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView->isColumnHidden(column)) {
                                               QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                           }
                                       }
                                       out << "</tr>\n";
                                   }
                                   out <<  "</table> </center>\n"
                                       "</body>\n"
                                       "</html>\n";

                             QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                              QPrinter printer (QPrinter::PrinterResolution);
                               printer.setOutputFormat(QPrinter::PdfFormat);
                              printer.setPaperSize(QPrinter::A4);
                             printer.setOutputFileName(fileName);

                              QTextDocument doc;
                               doc.setHtml(strStream);
                               doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                               doc.print(&printer);
}


void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tableView->setModel(C.rechercher(arg1));

}





void MainWindow::on_pushButton_5_clicked()
{
    QTableView *table;
                   table = ui->tableView;

                   QString filters("CSV files (.csv);;All files (.*)");
                                 QString defaultFilter("CSV files (*.csv)");
                   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                      filters, &defaultFilter);
                   QFile file(fileName);

                   QAbstractItemModel *model =  table->model();
                   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                       QTextStream data(&file);
                       QStringList strList;
                       for (int i = 0; i < model->columnCount(); i++) {
                           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") << "\n";
                       for (int i = 0; i < model->rowCount(); i++) {
                           strList.clear();
                           for (int j = 0; j < model->columnCount(); j++) {

                               if (model->data(model->index(i, j)).toString().length() > 0)
                                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") + "\n";
                       }
                       file.close();
                       QMessageBox::information(nullptr, QObject::tr("Import excel"),
                                                 QObject::tr("Import avec succes .\n"
                                                             "Click OK to exit."), QMessageBox::Ok);
                   }
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    ui->dateEdit_5->setDate(ui->calendarWidget->selectedDate());
}



void MainWindow::on_pushButton_9_clicked()
{

    int ref_cle=ui->comboBox_3->currentIndex();

    QString prenom=ui->lineEdit_3->text();
    QDate date_cle=ui->dateEdit_5->date();


    calendrier k(ref_cle,date_cle);
    bool test=k.ajouter1();
    QMessageBox msgbox;
    if(ref_cle!=0)
    {
    if(test)
    {msgbox.setText("Ajout avec succes.");

        ui->tableView_2->setModel(k.afficher1());

videz_label();
    }
    else
        msgbox.setText("Echec d'ajout");
    msgbox.exec();
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                             QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_radioButton_clicked()
{
    ui->tableView_2->setModel(k.triasc());
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView_2->setModel(k.tridesc());
}






void MainWindow::on_pushButton_6_clicked()
{

        QMediaPlayer* player = new QMediaPlayer;
        QVideoWidget* vw=new QVideoWidget;
        QSlider* slider;
        QProgressBar* bar;

        player->setVideoOutput(vw);
        this->setCentralWidget(vw);//thotha fel west el app

        player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/video_echhar.mpg"));

        //vw->setGeometry(100,100,1200,500);
        vw->show();

        player->play();



        //qDebug() << player->state();
        slider = new QSlider(this);
        bar= new QProgressBar(this);
        slider->setOrientation(Qt::Horizontal);
        ui->statusBar->addPermanentWidget(slider);
        ui->statusBar->addPermanentWidget(bar);
        connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
        connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
        connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

        connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
        connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}







using namespace DuarteCorporation;
void MainWindow::on_pushButton_7_clicked()
{
Widget* widget = new Widget;
this->setCentralWidget(widget);
widget->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    if(ui->tableView->currentIndex().row()==-1)
                        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                 QObject::tr("Veuillez Choisir un contrat du Tableau.\n"
                                                             "Click Ok to exit."), QMessageBox::Ok);
                    else
                    {
                         int  Code=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
                         const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
                         std::ofstream myfile;
                         myfile.open ("qrcode.svg") ;
                         myfile << qr.toSvgString(1);
                         myfile.close();
                         QSvgRenderer svgRenderer(QString("qrcode.svg"));
                         QPixmap pix( QSize(90, 90) );
                         QPainter pixPainter( &pix );
                         svgRenderer.render(&pixPainter);
                         ui->qrcode->setPixmap(pix);
                    }
}
