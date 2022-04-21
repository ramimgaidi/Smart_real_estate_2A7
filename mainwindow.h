#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include <QMainWindow>
#include "src/SmtpMime"
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
#include "arduino.h"
#include <QSystemTrayIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void afficherBD();
void afficherBD2();
QString filename;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();
void update_label();
private:
    arduino A;
        QByteArray data;
    reclamation R;
   Ui::MainWindow *ui;
   QSystemTrayIcon *MSystem;
};


#endif // MAINWINDOW_H
