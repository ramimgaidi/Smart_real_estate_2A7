#ifndef CHATBOXCONNECTIONDIALOG_H
#define CHATBOXCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ChatboxConnectionDialog;
}
namespace DuarteCorporation{
class ChatboxConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatboxConnectionDialog(QWidget *parent = nullptr);
    ~ChatboxConnectionDialog();
QString hostname() const;
quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::ChatboxConnectionDialog *ui;
    QString nHostname;
    quint16 nPort;
};
inline QString ChatboxConnectionDialog::hostname() const
{
    return nHostname;
}
inline quint16 ChatboxConnectionDialog::port() const
{
    return nPort;
}
}

#endif // CHATBOXCONNECTIONDIALOG_H
