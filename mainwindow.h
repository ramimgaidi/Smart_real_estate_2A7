#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
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
void afficherBD();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

private:
    reclamation R;
   Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
