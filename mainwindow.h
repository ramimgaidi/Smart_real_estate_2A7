#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contrat.h"
#include "widget.h"
#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>
#include <QProgressBar>

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
void afficherBD1();
void videz_label();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);


    void on_lineEdit_7_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_4_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_groupBox_windowIconTextChanged(const QString &iconText);

    void on_groupBox_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_5_clicked();

    void on_dateEdit_5_userDateChanged(const QDate &date);

    void on_groupBox_windowTitleChanged(const QString &title);

    void on_calendarWidget_selectionChanged();

    void on_pushButton_9_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();



private:
    contrat C;
    calendrier k;
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;

};

#endif // MAINWINDOW_H
