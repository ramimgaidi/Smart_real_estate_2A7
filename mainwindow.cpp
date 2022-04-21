#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finance.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "connection.h"
#include "historique.h"
#include "widget.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include <QSystemTrayIcon>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    mMediaPlayer = new QMediaPlayer(this);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](quint64 pos){
    ui->avance_2->setValue(pos);
    });

    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](quint64 dur){
        ui->avance_2->setMaximum(dur);

    });

    ui->lineEdit->setValidator( new QIntValidator(0, 99999999, this));
    //ui->lineEdit_4->setValidator( new QIntValidator(0, 99999999, this));
   //ui->lineEdit_7->setValidator( new QIntValidator(0, 99999999, this));
    ui->lineEdit_3->setValidator( new QIntValidator(0, 99999999, this));
    ui->lineEdit_6->setValidator( new QIntValidator(0, 99999999, this));
    ui->combo_id->addItem("");
    ui->combo_id_2->addItem("");
    historique h;
    ui->historique->setText(h.imprimer_hist());

    MSystem = new QSystemTrayIcon(this);
    MSystem->setVisible(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int id_finance=ui->lineEdit->text().toInt();
    QString type_trans=ui->comboBox_2->currentText();
    int revenance=ui->lineEdit_3->text().toInt();
    QDate datee=ui->dateEdit->date();
    Finance F(id_finance,type_trans,revenance,datee);
    int controle=0;
    QMessageBox msgbox;
    if(id_finance==0 || revenance==0 || type_trans.size()==0)
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                               QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
        controle=2;
    }
    if(!F.DateValide(datee))
    {
       msgbox.setText("date invalide");
       controle=1;
    }

    if (controle==0)
    {
        bool test=F.ajouter();
        if(test)
        {msgbox.setText("Ajout avec succes.");
            on_tabWidget_currentChanged(1);
            historique h;
            h.enregistrer_txt(ui->lineEdit->text(),type_trans,ui->lineEdit_3->text(),ui->dateEdit->date().toString());
            ui->combo_id->addItem(ui->lineEdit->text());
            ui->combo_id_2->addItem(ui->lineEdit->text());
            ui->historique->setText(h.imprimer_hist());
            ui->tableView->setModel(F.afficher());
            ui->comboBox_2->setCurrentText("");
            ui->lineEdit->setText("");
            ui->lineEdit_3->setText("");
            videz_label();

        }
        else
            msgbox.setText("Echec d'ajout");
    }
    msgbox.exec();
    }


void MainWindow::on_pushButton_2_clicked()
{
    int id_finance=ui->combo_id->currentIndex();
    QString type_trans=ui->comboBox->currentText();
        int revenance=ui->lineEdit_6->text().toInt();
        QDate datee=ui->dateEdit_2->date();
        Finance F(id_finance,type_trans,revenance,datee);


        F.setid_finance(ui->combo_id->currentIndex()) ;
        bool test=F.modifier(F.getid_finance()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            on_tabWidget_currentChanged(1);
            videz_label();

            ui->tableView->setModel(F.afficher());
        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Finance F1; F1.setid_finance(ui->combo_id_2->currentText().toInt());
    QMessageBox msgbox;
        msgbox.setText("voulez-vous le supprimer ?");
        msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            F1.supprimer(F1.getid_finance());
            ui->tableView->setModel(F.afficher());
            ui->combo_id_2->removeItem(ui->combo_id_2->currentIndex());
            ui->combo_id->removeItem(ui->combo_id_2->currentIndex());
            videz_label();
            msgbox.setText("Suppression avec succes...");
            on_tabWidget_currentChanged(1);
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
    //if(test)
    //{msgbox.setText("Suppression avec succes.");
      //  ui->tableView->setModel(F.afficher());
        //videz_label();
    //}
    //else
      //  msgbox.setText("Echec de suppression");
    //msgbox.exec();
}
void MainWindow::afficherBD()
{
Finance afe;
ui->tableView->setModel(afe.afficher());
QSqlQuery qry;
qry.prepare("select id_finance from finance");
qry.exec();
while(qry.next())
{
    ui->combo_id->addItem(qry.value("ID_FINANCE").toString());
    ui->combo_id_2->addItem(qry.value("ID_FINANCE").toString());
}

}
void MainWindow::videz_label()
{
    ui->lineEdit->setText("");
    ui->comboBox_2->currentText();
    ui->lineEdit_3->setText("");
    ui->dateEdit->date();
    //ui->lineEdit_4->setText("");
    ui->comboBox->currentText();
    ui->lineEdit_6->setText("");
    ui->dateEdit_2->date();
    //ui->lineEdit_7->setText("");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    Finance f;
        // background //
                  QLinearGradient gradient(0, 0, 0, 400);
                  gradient.setColorAt(0, QColor(220, 200, 200));
                  gradient.setColorAt(0.38, QColor(200, 200, 220));
                  gradient.setColorAt(0.38, QColor(000, 200, 200));
                  ui->plot->setBackground(QBrush(gradient));

                  QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                  amande->setAntialiased(false);
                  amande->setStackingGap(1);
                   //couleurs
                  amande->setName("Repartition selon revenance");
                  amande->setPen(QPen(QColor(0, 100, 100).lighter(130)));
                  amande->setBrush(QColor(0, 146, 200));

                   //axe des abscisses
                  QVector<double> ticks;
                  QVector<QString> labels;
                  f.statistique(&ticks,&labels);

                  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                  textTicker->addTicks(ticks, labels);
                  ui->plot->xAxis->setTicker(textTicker);
                  ui->plot->xAxis->setTickLabelRotation(60);
                  ui->plot->xAxis->setSubTicks(false);
                  ui->plot->xAxis->setTickLength(0, 4);
                  ui->plot->xAxis->setRange(0, 8);
                  ui->plot->xAxis->setBasePen(QPen(Qt::black));
                  ui->plot->xAxis->setTickPen(QPen(Qt::black));
                  ui->plot->xAxis->grid()->setVisible(true);
                  ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                  ui->plot->xAxis->setTickLabelColor(Qt::black);
                  ui->plot->xAxis->setLabelColor(Qt::black);

                  // axe des ordonnées
                  ui->plot->yAxis->setRange(0,10);
                  ui->plot->yAxis->setPadding(5);
                  ui->plot->yAxis->setLabel("Revenance");
                  ui->plot->yAxis->setBasePen(QPen(Qt::black));
                  ui->plot->yAxis->setTickPen(QPen(Qt::black));
                  ui->plot->yAxis->setSubTickPen(QPen(Qt::black));
                  ui->plot->yAxis->grid()->setSubGridVisible(true);
                  ui->plot->yAxis->setTickLabelColor(Qt::black);
                  ui->plot->yAxis->setLabelColor(Qt::black);
                  ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                  ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                  // ajout des données  (statistiques du finance)//

                  QVector<double> PlaceData;
                  QSqlQuery q1("select REVENANCE  from FINANCE");
                  while (q1.next()) {
                                int  nbr_fautee = q1.value(0).toInt();
                                PlaceData<< nbr_fautee;
                                  }
                  amande->setData(ticks, PlaceData);

                  ui->plot->legend->setVisible(true);
                  ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                  ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                  ui->plot->legend->setBorderPen(Qt::NoPen);
                  QFont legendFont = font();
                  legendFont.setPointSize(5);
                  ui->plot->legend->setFont(legendFont);
                  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}




void MainWindow::on_comboBox_3_activated(int index)
{

    QSqlQuery query;
    int id_finance=ui->combo_id->currentIndex() ;
   query.prepare("Select * from FINANCE where id_finance=:id_finance" );
           query.bindValue(0,id_finance) ;
           query.exec();
    query.next() ;
    //F.FINANCE(FINANCE);
    ui->comboBox->setCurrentText(query.value("type_trans").toString());
    ui->lineEdit_6->setText(query.value(2).toString());
    ui->dateEdit_2->setDate(query.value(3).toDate());

}

void MainWindow::on_combo_id_activated(const QString &arg1)
{
    QSqlQuery query;
    int id_finance=ui->combo_id->currentIndex() ;
   query.prepare("Select * from FINANCE where id_finance=:id_finance" );
           query.bindValue(0,id_finance) ;
           query.exec();
    query.next() ;
   // F.FINANCE(FINANCE);
    ui->comboBox->setCurrentText(query.value("type_trans").toString());
    ui->lineEdit_6->setText(query.value(2).toString());
    ui->dateEdit_2->setDate(query.value("datee").toDate());
}

void MainWindow::on_pushButton_4_clicked()
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

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(F.rechercher(arg1));
}



void MainWindow::on_pushButton_5_clicked()
{
    Finance F;
    QString crit=ui->comboBox_4->currentText();
    if(crit=="ID_FINANCE")
    {
        ui->tableView->setModel(F.tri_id_finance());
    }
    else if(crit=="TYPE_TRANS")
    {
        ui->tableView->setModel(F.tri_type_trans());
    }
}

void MainWindow::on_pushButton_6_clicked()
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
                                           "<center> <H1>Liste des Finances</H1></br></br><table border=2 cellspacing=0 cellpadding=2>\n";

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

void MainWindow::on_pushButton_7_clicked()
{
    int a;

   Finance F;
   a=F.calcule_revenance(F);
   if (a>1000)
   MSystem->showMessage(tr("notification"),tr("La revenance a dépassée 1000"));

   // QMessageBox::information(this, "My Title", "La revenance total est :");
   // QMessageBox msgbox ;
   //msgbox.setText(QString::F.calcule_revenance()) ;
   //msgbox.exec() ;
}



void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title", "voulez-vous quitter ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "No is clicked";
    }
}

using namespace DuarteCorporation;
void MainWindow::on_pushButton_9_clicked()
{
    Widget* widget = new Widget;
    this->setCentralWidget(widget);
    widget->show();

}
void MainWindow::on_pushButton_15_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"ouvrir");
    if (filename.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volume_2->value());
    on_pushButton_14_clicked();
}

void MainWindow::on_pushButton_14_clicked()
{
    mMediaPlayer->play();
}

void MainWindow::on_pushButton_17_clicked()
{
    mMediaPlayer->pause();

}


void MainWindow::on_volume_2_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);

}

void MainWindow::on_mute_2_clicked()
{
    if (ui->mute_2->text() == "Mute"){
        mMediaPlayer->setMuted(true);
        ui->mute_2->setText("Unmute");
    }
    else {
        mMediaPlayer->setMuted(false);
        ui->mute_2->setText("Mute");
    }
}

void MainWindow::on_radioButton_clicked()
{
    ui->tableView->setModel(F.tri_id_finance());
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView->setModel(F.tri_id_2_finance());

}
void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
    {

        ui->label_25->setText("Correcte"); // si les données reçues de arduino via la liaison série sont égales à 1
        MSystem->showMessage(tr("notification"),tr("La caisse est ouverte"));
    }


    else if (data=="0")
    {

        ui->label_25->setText("Incorrect");   // si les données reçues de arduino via la liaison série sont égales à 0
        MSystem->showMessage(tr("notification"),tr("Veuillez réessayer"));

    }

}


void MainWindow::on_pushButton_12_clicked()
{
   QString code = ui->lineEdit_4->text();
   if (F.recherche_ref(code))
   {
       //ui->label_25->setText("correcte");
       A.write_to_arduino("1"); //envoyer 1 à arduino
       //MSystem->showMessage(tr("notification"),tr("La caisse est ouverte"));


   }
   else
   {

       //ui->label_25->setText("Incorrecte");
       A.write_to_arduino("0"); //envoyer 0 à arduino
       //MSystem->showMessage(tr("notification"),tr("Veuillez réessayer"));

   }


}
