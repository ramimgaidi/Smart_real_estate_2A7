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

private:
    employe E;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
