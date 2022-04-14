#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>

namespace Ui {
class widget1;
}
class QMediaPlayer;

class widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget1(QWidget *parent = nullptr);
    ~widget1();

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_volume_2_valueChanged(int value);

    void on_mute_2_clicked();

private:
    Ui::widget1 *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // WIDGET1_H
