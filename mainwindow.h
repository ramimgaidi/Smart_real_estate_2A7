#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "finance.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "arduino.h"

namespace Ui {
class MainWindow;
}
class QMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void afficherBD();
    void videz_label();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_comboBox_3_activated(int index);

    void on_combo_id_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_volume_2_valueChanged(int value);

    void on_mute_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();
    void update_label();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


private:
    Finance F;
    Ui::MainWindow *ui;
    QMediaPlayer *mMediaPlayer;
    QSystemTrayIcon *MSystem;
    Arduino A;
    QByteArray data;

};

#endif // MAINWINDOW_H
