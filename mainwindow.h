#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void videz_label();
    void afficherBD();


private slots:
    //void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

    void on_ajouter_employe_clicked();

    void on_pushButton_clicked();

    void on_supprimer_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_recher_edit2_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_afficher_liste_clicked();

private:
    employe E;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
